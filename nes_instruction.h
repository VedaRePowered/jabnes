#ifndef NES_INSTRUCTION_H
#define NES_INSTRUCTION_H

#include <string>

#include "state.h"

const unsigned short MODE_NOTHING = 0;
const unsigned short MODE_IMMEDIATE = 1;
const unsigned short MODE_ZEROPAGE = 2;
const unsigned short MODE_ZEROPAGEX = 3;
const unsigned short MODE_ZEROPAGEY = 4;
const unsigned short MODE_ABSOLUTE = 5;
const unsigned short MODE_ABSOLUTEX = 6;
const unsigned short MODE_ABSOLUTEY = 7;
const unsigned short MODE_INDIRECT = 8;
const unsigned short MODE_INDIRECTX = 9;
const unsigned short MODE_INDIRECTY = 10;
const unsigned short MODE_RELATIVE = 11;

void dummy(state&, unsigned short a, unsigned short * b);

// define instruction class
class nes_instruction {
public:
	nes_instruction();
	nes_instruction(unsigned short, unsigned short, char, bool, std::string, void (*execute_function)(state&, unsigned short, unsigned short *));
	nes_instruction(unsigned short, unsigned short, char, bool, std::string, void (*execute_function)(state&, unsigned short, unsigned short *), bool);
	nes_instruction(unsigned short, unsigned short, char, bool, std::string, void (*execute_function)(state&, unsigned short, unsigned short *), bool, bool);

	unsigned short cycles; // number of CPU cycles it takes to execute
	unsigned short address_type; // type of address
	char pram_register; // pointer to the register for the second parameter
	bool page_boundary_slowdown = false; // should the instruction take one more cycle if it crosses a page boundary
	char opcode[4]; // opcode name
	bool is_branch;
	bool is_unofficial;

	void (*execute_function)(state&, unsigned short, unsigned short *); // function to execute with two litaral numbers
};

#endif
