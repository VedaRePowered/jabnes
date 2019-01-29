#include <iostream>
#include <queue>
#include <fstream>

#include "ppu.h"
#include "state.h"

struct position {
	unsigned short x;
	unsigned short y;
	bool colliding;
};

ppu::ppu() {}

position get_pos_of_ppu_clock(unsigned short ppu_clock) {
	position pos;
	pos.x = ppu_clock % 341;
	pos.y = ppu_clock / 341 - 21;
	pos.colliding = (pos.x < 256) & (pos.y < 240);
	return pos;
}

void ppu::set_buffer_pixel(unsigned short x, unsigned short y, unsigned short colour) {
	colour = colour & 0x3F;
	x = x & 0xFF;
	y = y & 0xFF;
	this->buffer[x + (y*256)] = colour;
}
unsigned short ppu::get_buffer_pixel(unsigned short x, unsigned short y) {
	x = x & 0xFF;
	y = y & 0xFF;
	return this->buffer[x + (y*256)] & 0x3F;
}
void ppu::draw_from_queue(state& current_state, std::queue<ppu_change_element>& draw_queue) {
	unsigned short ppu_control;
	unsigned short ppu_mask;
	unsigned short ppu_scroll_x;
	unsigned short ppu_scroll_y;
	unsigned short ppu_address;
	bool scroll_vert;

	unsigned change_pixel = 0;
	unsigned last_change_pixel = 0;
	// std::cout << "ppuFrame queue size: " << draw_queue.size() << std::endl;
	while (draw_queue.size() > 0) {
		ppu_change_element tmp = draw_queue.front();

		draw_queue.pop();
		last_change_pixel = change_pixel;
		change_pixel = tmp.cpu_clock * 3; // cpu_clock * 3 = ppu_clock

		// draw from last_change_pixel to change_pixel before setting the new registers
		for (unsigned ppu_clock = last_change_pixel; ppu_clock < change_pixel; ppu_clock+=8) {
			position pixel = get_pos_of_ppu_clock(ppu_clock);
			if (pixel.colliding) {
				// std::cout << "pixel x:" << pixel.x << ", y:" << pixel.y << std::endl;
				unsigned short nametable_x = pixel.x>>3; // divide by 8
				unsigned short nametable_y = pixel.y>>3; // divide by 8
				nametable_x += ppu_scroll_x>>3;
				nametable_y += ppu_scroll_y>>3;
				if (ppu_control & 0b00000001) {
					nametable_x += 256>>3;
				}
				if (ppu_control & 0b00000010) {
					nametable_y += 240>>3;
				}
				unsigned short nametable_address = 0x2000;
				if (nametable_x >= 256>>3) {
					nametable_address += 0x0400;
					nametable_x &= 0xFF>>3;
				}
				if (nametable_y >= 240>>3) {
					nametable_address += 0x0800;
					nametable_y -= 240>>3;
				}

				unsigned short palette_x = nametable_x>>2;
				unsigned short palette_y = nametable_y>>2;
				unsigned short palette = current_state.get_ppu_memory(palette_x + (palette_y>>3) + nametable_address + 0x03C0);
				if (!(nametable_x>>1 & 0b00000001)) {
					palette = palette >> 2;
				}
				if (nametable_y>>1 & 0b00000001) {
					palette = palette >> 4;
				}
				palette = palette & 0b00000011;

				nametable_address += nametable_x;
				nametable_address += nametable_y<<8; // mulltiply by 256

				// std::cout << "nametable_address " << nametable_address << std::endl;
				unsigned short tile = current_state.get_ppu_memory(nametable_address);
				unsigned short palette_colour_high_byte;
				unsigned short palette_colour_low_byte;
				if (!(ppu_control & 0b00010000)) { // pattern table select (0x0000 or 0x1000)
					palette_colour_high_byte = current_state.get_ppu_memory(tile>>4);
					palette_colour_low_byte = current_state.get_ppu_memory((tile>>4)+8);
				} else {
					palette_colour_high_byte = current_state.get_ppu_memory((tile>>4)+0x1000);
					palette_colour_low_byte = current_state.get_ppu_memory((tile>>4)+0x1000+8);
				}

				unsigned short palette_colours[4];
				palette_colours[0] = current_state.get_ppu_memory(0x3F00);
				palette_colours[1] = current_state.get_ppu_memory(0x3F01+(palette<<2));
				palette_colours[2] = current_state.get_ppu_memory(0x3F02+(palette<<4));
				palette_colours[3] = current_state.get_ppu_memory(0x3F03+(palette<<6));

				for (int i = 0; i < 8; i++) {
					unsigned short palette_colour_bits = (palette_colour_low_byte>>(7-i))&0b00000001;
					palette_colour_bits |= ( (palette_colour_high_byte>>(7-i))&0b00000001 )<<1;
					unsigned short colour = palette_colours[palette_colour_bits];
					if (ppu_mask & 0b00000001) { // grayscale
						colour = colour & 0x30;
					}
					this->set_buffer_pixel(pixel.x+i, pixel.y, colour);
				}
			}
		}

		switch (tmp.changed_register) {
			case 'c':
				ppu_control = tmp.ppu_control;
			case 'm':
				ppu_mask = tmp.ppu_mask;
				break;
			case 's':
				if (scroll_vert) {
					ppu_scroll_y = tmp.ppu_scroll;
				} else {
					ppu_scroll_x = tmp.ppu_scroll;
				}
				scroll_vert = !scroll_vert;
				break;
			case 'p' ^ 'a':
				ppu_address = tmp.ppu_address;
				break;
			case 'p' ^ 'd':
				current_state.set_ppu_memory(ppu_address, tmp.ppu_data);
				break;
		}
	}
}


unsigned short * ppu::get_buffer() {
	return this->buffer;
}

void ppu::load_pal(colour * pal, const char * fname, bool debug) {
	std::ifstream palette_file;
	palette_file.open(fname);
	for (int i = 0; i < 64; i++) {
		unsigned char c[3];
		palette_file.read((char *)c, 0x3);
		pal[i].nes_id = i;
		pal[i].r = c[0];
		pal[i].g = c[1];
		pal[i].b = c[2];
		if (debug) {
			std::cout << "pallet@" << i << ": ";
			std::cout << "r=" << pal[i].r << ", g=" << pal[i].g << ", b=" << pal[i].b;
			std::cout << std::endl;
		}
	}
}
