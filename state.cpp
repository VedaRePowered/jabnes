#include "state.h"

unsigned short int reg_dummy;
int last_joy_1_read = -1;
int last_joy_2_read = -1;

state::state() {
	// build an array for mapping nes cpu memory
	for (int i=0x0000; i <= 0x07FF; i++) {
		this->cpu_memory_map[i+0x0800*0] = &(ram[i]);
		this->cpu_memory_map[i+0x0800*1] = &(ram[i]);
		this->cpu_memory_map[i+0x0800*2] = &(ram[i]);
		this->cpu_memory_map[i+0x0800*3] = &(ram[i]);
	}
	for (int i=0; i <= 7; i++) {
		for (int o; o < 1024; o+= 8) {
			this->cpu_memory_map[0x2000+i+o] = &(ppu_regs[i]);
		}
	}
	for (int i=0x4000; i <= 0x40016; i++) {
		this->cpu_memory_map[i] = &(apu_regs[i-0x4000]);
	}
	for (int i=0x4017; i <= 0x401F; i++) {
		this->cpu_memory_map[i] = &reg_dummy; // not emulating CPU test mode, and joysticks are a special case in the memory getting function
	}
	for (int i=0x4020; i <= 0xFFFF; i++) {
		this->cpu_memory_map[i] = &(cart_mem[i-4020]);
	}

	this->reg_a = 0;
	this->reg_x = 0;
	this->reg_y = 0;
	this->reg_s = 0;
	this->reg_p = 0;
	this->reg_pc = 0xC000; // start position for nestest
}

unsigned short int * state::get_reg(char reg) {
	switch(reg) {
		case 'a': return &reg_a;
		case 'x': return &reg_x;
		case 'y': return &reg_y;
		case 's': return &reg_s;
		case 'p': return &reg_p;
		case 'c': return &reg_pc;
	}
	return &reg_dummy;
}
void state::set_reg(char reg, unsigned short int val) {
	val = val & 0x00FF;
	*(get_reg(reg)) = val;
}

unsigned short int * state::get_memory(unsigned short int loc) {
	if(loc == 0x4017) {
		return (unsigned short int)0;
	} else if (loc == 0x4018) {
		return (unsigned short int)0;
	} else {
		return cpu_memory_map[loc];
	}
}

void state::set_memory(unsigned short int loc, unsigned short int val) {
	if(loc == 0x4017) {
	} else if (loc == 0x4018) {
	} else {
		*(get_memory(loc)) = val;
	}
}
