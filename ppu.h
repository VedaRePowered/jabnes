#ifndef PPU_H
#define PPU_H

#include <queue>

#include "state.h"

struct colour {
	unsigned int nes_id;
	unsigned int r;
	unsigned int g;
	unsigned int b;
};

struct ppu_change_element {
	unsigned short ppu_control;
	unsigned short ppu_mask;
	unsigned short oam_address;
	unsigned short oam_data;
	unsigned short ppu_address;
	unsigned short ppu_data;
	unsigned short ppu_scroll;
	char changed_register;
	unsigned cpu_clock;
};

class ppu{
public:
	ppu(void);
	void draw_pixels(state& current_state, std::queue<ppu_change_element> draw_queue);
	void set_buffer_pixel(unsigned short x, unsigned short y, unsigned short colour);
	unsigned short get_buffer_pixel(unsigned short x, unsigned short y);
	void draw_queue(state& current_state, std::queue<ppu_change_element> draw_queue);
	unsigned short * get_buffer(void);
	void load_pal(colour *, char *);
private:
	unsigned short buffer[61440];
};

#endif
