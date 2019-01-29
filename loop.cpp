#include <iostream>
#include <cairomm/context.h>
#include <glibmm/main.h>
#include <math.h>

#include <queue>

#include "loop.h"
#include "ppu.h"

JabnesCanvas::JabnesCanvas() {
	std::cout << "+------------------+ JABNES p0.0.2:" << std::endl;
	std::cout << "| J  A  B  N  E  S | - Creator: BEN1JEN" << std::endl;
	std::cout << "| u  n  a  i  m  o | - Licence: GPL 3.0" << std::endl;
	std::cout << "| s  o  s  n  u  f | - Ganra: Emulator" << std::endl;
	std::cout << "| t  t  i  t  l  t | - - System: NES" << std::endl;
	std::cout << "|    h  c  e  a  w | - - Supported ROMs: none" << std::endl;
	std::cout << "|    e     n  t  a | - - Emulated: CPU (no unofficial opcodes)" << std::endl;
	std::cout << "|    r     d  i  r | - Has Base Features: No" << std::endl;
	std::cout << "|          o  o  e | - Build Type: pre-alpha" << std::endl;
	std::cout << "|             n    | - Platforms: Linux" << std::endl;
	std::cout << "+------------------+ - Git Repo: https://gitlab.101100.ca/ben1jen/jabnes" << std::endl;
	std::cout << "\033[53mLog Output:                                                             \033[0m" << std::endl;
	current_state.load_rom("SMB1.nes");
	nes_ppu.load_pal(this->palette, "generated.pal", false);
	for (int y = 0; y < 240; y++) {
		for (int x = 0; x < 256; x++) {
			nes_ppu.set_buffer_pixel(x, y, 31);
		}
	}

	for (int i=0x0000; i <= 0x03FF; i++) {
		for (int j=0; j<4; j++) {
			current_state.set_ppu_memory(0x2400+i+j*0x0400, 3);
		}
	}

	Glib::signal_timeout().connect( sigc::mem_fun(*this, &JabnesCanvas::on_timeout), 20 );
}

JabnesCanvas::~JabnesCanvas() {
	std::cout << "Stoping emulation..." << std::endl;
}

bool JabnesCanvas::on_timeout() {

	ppu_change_element tmp = {
		*current_state.get_memory(0x2000),
		*current_state.get_memory(0x2001),
		*current_state.get_memory(0x2003),
		*current_state.get_memory(0x2004),
		*current_state.get_memory(0x2006),
		*current_state.get_memory(0x2007),
		*current_state.get_memory(0x2005),
		0,
		0
	};
	current_state.ppu_queue.push(tmp);

	current_state.reset_cycle();
	while (current_state.get_cycle() < 33248) {
		nes_cpu.execute_instruction(current_state, false);
	}

	ppu_change_element tmp2 = {
		*current_state.get_memory(0x2000),
		*current_state.get_memory(0x2001),
		*current_state.get_memory(0x2003),
		*current_state.get_memory(0x2004),
		*current_state.get_memory(0x2006),
		*current_state.get_memory(0x2007),
		*current_state.get_memory(0x2005),
		0,
		33247
	};
	current_state.ppu_queue.push(tmp2);

	nes_ppu.draw_from_queue(current_state, current_state.ppu_queue);

	// force cairo to redraw the entire canvas.
	auto win = get_window();
	if (win)
	{
		Gdk::Rectangle r(0, 0, get_allocation().get_width(), get_allocation().get_height());
		win->invalidate_rect(r, false);
	}

	return true;

}

bool JabnesCanvas::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
	Gtk::Allocation allocation = get_allocation();
	const int width = allocation.get_width();
	const int height = allocation.get_height();

	double xScale = width/256.0;
	double yScale = height/240.0;
	double fScale = xScale < yScale ? xScale : yScale;
	int viewportSize = xScale < yScale ? width : height;
	int scale = (int)floor(fScale);
	double extraPixelRate = 1.0/(fScale - scale);

	int xOffset = (width - viewportSize)/2 - 1;
	int yOffset = (height - viewportSize)/100000 - 1;

	int yPixelOffset = 0;
	for (int y = 0; y < 240; y++) {
		int xPixelOffset = 0;

		int localYScale = scale+1;
		if (floor(fmod(y, extraPixelRate)) == 0) {
			localYScale++;
			yPixelOffset++;
		}

		for (int x = 0; x < 256; x++) {
			unsigned short p = nes_ppu.get_buffer_pixel(x, y);
			colour c = this->palette[p];

			int localXScale = scale+1;
			if (floor(fmod(x, extraPixelRate)) == 0) {
				localXScale++;
				xPixelOffset++;
			}

			cr->save();
			cr->set_source_rgb(c.r/256.0, c.g/256.0, c.b/256.0);

			cr->rectangle(x*scale+xPixelOffset+xOffset, y*scale+yPixelOffset+yOffset, localXScale, localYScale);
			cr->fill();
			cr->restore();
		}
	}

	return true;
}
