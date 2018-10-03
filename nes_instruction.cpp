#include <cstddef>

#include "nes_instruction.h"

void dummy(unsigned short int a, unsigned short int b) {
	// Do nothing
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
}

nes_instruction::nes_instruction(unsigned short int cycles, unsigned short int address_type, unsigned short int* pram_register, bool page_boundary_slowdown, std::string opcode, void (*execute_function)(unsigned short int, unsigned short int)) {
	this->cycles = cycles;
	this->address_type = address_type;
	this->pram_register = pram_register;
	this->page_boundary_slowdown = page_boundary_slowdown;
	this->opcode[0] = opcode[0];
	this->opcode[1] = opcode[1];
	this->opcode[2] = opcode[2];
	this->opcode[3] = '\0';
	this->execute_function = execute_function;
}
