#ifndef STATE_H
#define STATE_H

#include <cstddef>

#include "nes_instruction.h"

class state{
public:
	state();
	unsigned short int * get_reg(char reg);
	void set_reg(char reg, unsigned short int val);
	unsigned short int * get_memory(unsigned short int loc);
	void set_memory(unsigned short int loc, unsigned short int val);
private:
	unsigned short int reg_a;
	unsigned short int reg_x;
	unsigned short int reg_y;
	unsigned short int reg_s;
	unsigned short int reg_p;
	unsigned short int reg_pc;
	unsigned short int ram[0x0800];
	unsigned short int apu_regs[0x0016];
	unsigned short int ppu_regs[0x0008];
	unsigned short int cart_mem[0xBFE0];
	unsigned short int pattern_table[2][0x1000];
	unsigned short int name_table[4][0x0400];
	unsigned short int palette_ram[0x0020];
	unsigned short int oam_spr_x[0x0040];
	unsigned short int oam_spr_y[0x0040];
	unsigned short int oam_spr_n[0x0040];
	unsigned short int oam_spr_a[0x0040];
	unsigned short int * cpu_memory_map[0x10000];
};


#endif
