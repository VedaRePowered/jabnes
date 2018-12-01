#ifndef JABNES_LOOP_H
#define JABNES_LOOP_H

#include <gtkmm-3.0/gtkmm/drawingarea.h>

#include "instructions.h"
#include "state.h"
#include "ppu.h"

class JabnesCanvas : public Gtk::DrawingArea {
public:
	JabnesCanvas();
	~JabnesCanvas();
private:
	bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;

	bool on_timeout();

	cpu nes_cpu;
	state current_state;
	ppu nes_ppu;
	colour palette[64];
};

#endif
