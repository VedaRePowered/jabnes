#ifndef NES_INSTRUCTION_H
#define NES_INSTRUCTION_H

#include <string>

// define instruction class
class nes_instruction {
public:
	nes_instruction();
	nes_instruction(unsigned short int, unsigned short int, unsigned short int*, bool, std::string, void (*execute_function)(unsigned short int, unsigned short int));

	unsigned short int cycles; // number of CPU cycles it takes to execute
	unsigned short int address_type; // type of address, 0: Implied (None), 1: Zero Page, 2: Absolute, 3: Immediate, 4: Indirect
	unsigned short int * pram_register; // pointer to the register for the second parameter
	bool page_boundary_slowdown = false; // should the instruction take one more cycle if it crosses a page boundary
	char opcode[4]; // opcode name

	void (*execute_function)(unsigned short int, unsigned short int); // function to execute with two litaral numbers
};

#endif
