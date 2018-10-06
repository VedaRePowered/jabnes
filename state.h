#ifndef STATE_H
#define STATE_H

#include <cstddef>

class state{
public:
	state();
	unsigned short * get_reg(char reg);
	void set_reg(char reg, unsigned short val);
	void set_flag(char flag, bool val);
	unsigned short * get_memory(unsigned short loc);
	void set_memory(unsigned short loc, unsigned short val);
	bool load_rom(char const * location);
private:
	unsigned short reg_a;
	unsigned short reg_x;
	unsigned short reg_y;
	unsigned short reg_s;
	unsigned short reg_p;
	unsigned short reg_pc;
	unsigned short ram[0x0800];
	unsigned short apu_regs[0x0016];
	unsigned short ppu_regs[0x0008];
	unsigned short cart_mem[0xBFE0];
	unsigned short pattern_table[2][0x1000];
	unsigned short name_table[4][0x0400];
	unsigned short palette_ram[0x0020];
	unsigned short oam_spr_x[0x0040];
	unsigned short oam_spr_y[0x0040];
	unsigned short oam_spr_n[0x0040];
	unsigned short oam_spr_a[0x0040];
	unsigned short * cpu_memory_map[0x10000];
};


#endif
