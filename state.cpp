#include <iostream>
#include <fstream>

#include "state.h"

unsigned short reg_dummy;
int last_joy_1_read = -1;
int last_joy_2_read = -1;

unsigned short const_zero = 0;
unsigned short const_one = 1;

state::state() {
	// build an array for mapping nes cpu memory
	for (int i=0x0000; i <= 0x07FF; i++) {
		this->cpu_memory_map[i+0x0800*0] = &(ram[i]);
		this->cpu_memory_map[i+0x0800*1] = &(ram[i]);
		this->cpu_memory_map[i+0x0800*2] = &(ram[i]);
		this->cpu_memory_map[i+0x0800*3] = &(ram[i]);
	}
	for (int i=0; i <= 7; i++) {
		for (int o=0; o < 1024*8; o+= 8) {
			this->cpu_memory_map[0x2000+i+o] = &(ppu_regs[i]);
		}
	}
	for (int i=0x4000; i <= 0x4016; i++) {
		this->cpu_memory_map[i] = &(apu_regs[i-0x4000]);
	}
	for (int i=0x4017; i <= 0x401F; i++) {
		this->cpu_memory_map[i] = &reg_dummy; // not emulating CPU test mode, and joysticks are a special case in the memory getting function
	}
	for (int i=0x4020; i <= 0xFFFF; i++) {
		this->cpu_memory_map[i] = &(cart_mem[i-0x4020]);
	}

	// build an array for mapping nes ppu memory
	for (int i=0x0000; i <= 0x1FFF; i++) {
		this->ppu_memory_map[i] = &(pattern_table[0][i]);
		this->ppu_memory_map[i+0x1000] = &(pattern_table[1][i]);
	}
	for (int i=0x0000; i <= 0x03FF; i++) {
		for (int j=0; j<4; j++) {
			this->ppu_memory_map[0x2000+i+j*0x0400] = &(name_table[j][i]);
		}
	}
	for (int i=0x3000; i <= 0x3EFF; i++) {
		this->ppu_memory_map[i] = this->ppu_memory_map[i-0x1000];
	}
	for (int i=0x00; i <= 0x20; i++) {
		for (int o=0; o < 7*0x20; o += 0x20) {
			this->ppu_memory_map[0x3F00+i+o] = &(palette_ram[i]);
		}
	}
	for (unsigned i = 0x4000; i < 0x10000; i++) {
		this->ppu_memory_map[i] = &reg_dummy;
	}

	this->reg_a = 0;
	this->reg_x = 0;
	this->reg_y = 0;
	this->reg_s = 0xfd;
	this->reg_p = 0x24;
	this->reg_pc = 0xC000; // start position for nestest
}

unsigned short * state::get_reg(char reg) {
	switch(reg) {
		case 'a': return &reg_a;
		break;
		case 'x': return &reg_x;
		break;
		case 'y': return &reg_y;
		break;
		case 's': return &reg_s;
		break;
		case 'p': return &reg_p;
		break;
		case 'c': return &reg_pc;
		break;
		case 'd': return &reg_dummy;
		break;
	}
	return &reg_dummy;
}
void state::set_reg(char reg, unsigned short val) {
	if (!(reg=='c')) {
		val = val & 0x00FF;
	}
	if (reg=='p') {
		val = val & 0b11101111;
		val = val | 0b00100000;
	}
	*(get_reg(reg)) = val;
}

bool state::get_flag(char flag) {
	unsigned short flag_bit = 0;
	switch (flag) {
		case 'c': flag_bit = 0b00000001;
		break;
		case 'z': flag_bit = 0b00000010;
		break;
		case 'i': flag_bit = 0b00000100;
		break;
		case 'd': flag_bit = 0b00001000;
		break;
		case 'v': flag_bit = 0b01000000;
		break;
		case 'n': flag_bit = 0b10000000;
		break;
	}
	unsigned short status_reg_tmp = *(get_reg('p'));
	return status_reg_tmp & flag_bit;
}

void state::set_flag(char flag, bool val) {
	unsigned short flag_bit = 0;
	switch (flag) {
		case 'c': flag_bit = 0b00000001;
		break;
		case 'z': flag_bit = 0b00000010;
		break;
		case 'i': flag_bit = 0b00000100;
		break;
		case 'd': flag_bit = 0b00001000;
		break;
		case 'v': flag_bit = 0b01000000;
		break;
		case 'n': flag_bit = 0b10000000;
		break;
	}
	unsigned short status_reg_tmp = *(get_reg('p'));
	status_reg_tmp = status_reg_tmp & (~flag_bit);
	if (val) {
		status_reg_tmp = status_reg_tmp | flag_bit;
	}
	set_reg('p', status_reg_tmp);
}

unsigned short * state::get_memory(unsigned short loc) {
	const_zero = 0;
	const_one = 1;
	if (loc == 0x4017) {
		return &const_zero;
	} else if (loc == 0x4018) {
		return &const_zero;
	} else {
		return cpu_memory_map[loc];
	}
}

void state::set_memory(unsigned short loc, unsigned short val) {
	// std::cout << "WRITE @ " << std::hex << loc << " : " << std::hex << val << "\n";
	val = val & 0x00FF;
	if (loc == 0x4017) {
	} else if (loc == 0x4018) {
	} else {
		*(get_memory(loc)) = val;
	}
	if (loc >= 0x2000 && loc < 0x4000) {
		char changed = 0;
		switch (loc&7) {
			case 0:	changed = 'c';
						break;
			case 1:	changed = 'm';
						break;
			case 5:	changed = 's';
						break;
			case 6:	changed = 'A'; // ppu address
						break;
			case 7:	changed = 'D'; // ppu data
						// std::cout << "PPU_EXT_WRITE: " << val << "\n";
						break;
		}
		if (changed != 0) {
			ppu_change_element tmp = {
				*get_memory(0x2000),
				*get_memory(0x2001),
				*get_memory(0x2003),
				*get_memory(0x2004),
				*get_memory(0x2006),
				*get_memory(0x2007),
				*get_memory(0x2005),
				changed,
				cpu_cycle
			};
			ppu_queue.push(tmp);
		}
	}
}

unsigned short state::get_ppu_memory(unsigned short loc) {
	// std::cout << "PPU_READ:  " << loc << std::endl;
	return *(ppu_memory_map[loc]);
}

void state::set_ppu_memory(unsigned short loc, unsigned short val) {
	// std::cout << "PPU_WRITE: " << std::hex << val << "@" << std::hex << loc << std::endl;
	*(ppu_memory_map[loc]) = val;
}

bool state::load_rom(char const * location) {
	std::ifstream rom;
	rom.open(location, std::ios::binary);
	if (!rom){
		return false;
	}

	rom.seekg(0, std::ios::end);
	int rom_length = rom.tellg();
	rom.seekg(0, std::ios::beg);

	if (rom_length < 0x6010) {
		return false;
	}

	char header[0x10];
	rom.read(header, 0x10);

	if (header[0] != 'N' or header[1] != 'E' or header[2] != 'S' or header[3] != 0x1A) {
		return false;
	}

	unsigned short prg_banks = header[4];
	unsigned short chr_banks = header[5];
	unsigned short mapper = ( (header[6] >> 4) & 0x0F ) | ( (header[7]) & 0xF0 );

	if (mapper != 0) {
		return false;
	}

	bool rom_trainer_exists = header[6] & 0b00000100;
	int rom_trainer_length = rom_trainer_exists ? 0x200:0;

	int rom_min_size = 0x10 + 0x4000 * prg_banks + 0x2000 * chr_banks + rom_trainer_length;

	if (rom_length < rom_min_size) {
		return false;
	}

	if (prg_banks > 2) {
		return false;
	}
	if (chr_banks > 1) {
		return false;
	}

	rom.seekg(rom_trainer_length, std::ios::cur);

	for (int i=0; i<prg_banks; i++) {
		char prg_data[0x4000];
		rom.read(prg_data, 0x4000);
		if (i == 0) {
			for (int b=0; b<0x4000; b++) {
				cart_mem[0x3FE0 + b] = prg_data[b] & 0x00FF;
			}
		} else if (i == 1) {
			for (int b=0; b<0x4000; b++) {
				cart_mem[0x3FE0 + 0x4000 + b] = prg_data[b] & 0x00FF;
			}
		}
	}
	char chr_data[0x4000];
	rom.read(chr_data, 0x2000);
	for (int b=0; b<0x2000; b++) {
		pattern_table[0][b] = chr_data[b] & 0x00FF;
	}

	rom.close();

	return true;
}

void state::cpu_nmi() { // little endian jump vectors
	this->set_reg('c', *(this->get_memory(0xFFFA)) + (*(this->get_memory(0xFFFB)) << 8));
}

void state::cpu_reset() {
	this->set_reg('c', *(this->get_memory(0xFFFC)) + (*(this->get_memory(0xFFFD)) << 8));
}

void state::cpu_irq() {
	this->set_reg('c', *(this->get_memory(0xFFFE)) + (*(this->get_memory(0xFFFF)) << 8));
}

unsigned short state::get_cycle() {
	return this->cpu_cycle;
}

void state::reset_cycle() {
	this->cpu_cycle = 0;
}

void state::inc_cycle(unsigned short amount) {
	this->cpu_cycle += amount;
}
