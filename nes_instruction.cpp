#include <cstddef>

#include "nes_instruction.h"

void dummy(state&, unsigned short * a, unsigned short * b) {
	// Do nothing
	// and that you are
}

nes_instruction::nes_instruction() {
	this->cycles = 2;
	this->address_type = 0;
	this->pram_register = NULL;
	this->page_boundary_slowdown = false;
	this->opcode[0] = 'N';
	this->opcode[1] = 'O';
	this->opcode[2] = 'P';
	this->opcode[3] = '\0';
	this->execute_function = &dummy;
	this->is_branch = false;
}

nes_instruction::nes_instruction(unsigned short cycles, unsigned short address_type, unsigned short* pram_register, bool page_boundary_slowdown, std::string opcode, void (*execute_function)(state&, unsigned short *, unsigned short *)) {
	this->cycles = cycles;
	this->address_type = address_type;
	this->pram_register = pram_register;
	this->page_boundary_slowdown = page_boundary_slowdown;
	this->opcode[0] = opcode[0];
	this->opcode[1] = opcode[1];
	this->opcode[2] = opcode[2];
	this->opcode[3] = '\0';
	this->execute_function = execute_function;
	this->is_branch = false;
}
nes_instruction::nes_instruction(unsigned short cycles, unsigned short address_type, unsigned short* pram_register, bool page_boundary_slowdown, std::string opcode, void (*execute_function)(state&, unsigned short *, unsigned short *), bool is_branch) {
	this->cycles = cycles;
	this->address_type = address_type;
	this->pram_register = pram_register;
	this->page_boundary_slowdown = page_boundary_slowdown;
	this->opcode[0] = opcode[0];
	this->opcode[1] = opcode[1];
	this->opcode[2] = opcode[2];
	this->opcode[3] = '\0';
	this->execute_function = execute_function;
	this->is_branch = is_branch;
}
