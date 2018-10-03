#include <cstddef>

#include "nes_instruction.h"

// define registers
unsigned short int reg_a = 0;
unsigned short int reg_x = 0;
unsigned short int reg_y = 0;

/*
instructions[0xhh] = nes_instruction(
	t, // time
	m, // mode
	&reg_a, // pram 2
	false, // page boundary slowdown
	"ADD", // opcode
	NULL // function
);
*/

int main() {
	// define instructions
	nes_instruction instructions[256];
	//ADC instructions
	instructions[0x69] = nes_instruction(
		2, // time
		MODE_IMMEDIATE, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"ADC", // opcode
		NULL // function
	);
	instructions[0x65] = nes_instruction(
		3, // time
		MODE_ZEROPAGE, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"ADC", // opcode
		NULL // function
	);
	instructions[0x75] = nes_instruction(
		4, // time
		MODE_ZEROPAGEX, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"ADC", // opcode
		NULL // function
	);
	instructions[0x6D] = nes_instruction(
		4, // time
		MODE_ABSOLUTE, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"ADC", // opcode
		NULL // function
	);
	instructions[0x7D] = nes_instruction(
		4, // time
		MODE_ABSOLUTEX, // mode
		&reg_a, // pram 2
		true, // page boundary slowdown
		"ADC", // opcode
		NULL // function
	);
	instructions[0x79] = nes_instruction(
		4, // time
		MODE_ABSOLUTEY, // mode
		&reg_a, // pram 2
		true, // page boundary slowdown
		"ADC", // opcode
		NULL // function
	);
	instructions[0x61] = nes_instruction(
		6, // time
		MODE_INDIRECTX, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"ADC", // opcode
		NULL // function
	);
	instructions[0x71] = nes_instruction(
		5, // time
		MODE_INDIRECTY, // mode
		&reg_a, // pram 2
		true, // page boundary slowdown
		"ADC", // opcode
		NULL // function
	);
	//AND instructions
	instructions[0x29] = nes_instruction(
		2, // time
		MODE_IMMEDIATE, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"ADD", // opcode
		NULL // function
	);
	instructions[0x25] = nes_instruction(
		2, // time
		MODE_ZEROPAGE, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"ADD", // opcode
		NULL // function
	);
	instructions[0x35] = nes_instruction(
		3, // time
		MODE_ZEROPAGEX, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"ADD", // opcode
		NULL // function
	);
	instructions[0x2D] = nes_instruction(
		4, // time
		MODE_ABSOLUTE, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"ADD", // opcode
		NULL // function
	);
	instructions[0x3D] = nes_instruction(
		4, // time
		MODE_ABSOLUTEX, // mode
		&reg_a, // pram 2
		true, // page boundary slowdown
		"ADD", // opcode
		NULL // function
	);
	instructions[0x39] = nes_instruction(
		4, // time
		MODE_ABSOLUTEY, // mode
		&reg_a, // pram 2
		true, // page boundary slowdown
		"ADD", // opcode
		NULL // function
	);
	instructions[0x21] = nes_instruction(
		6, // time
		MODE_INDIRECTX, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"ADD", // opcode
		NULL // function
	);
	instructions[0x31] = nes_instruction(
		5, // time
		MODE_INDIRECTY, // mode
		&reg_a, // pram 2
		true, // page boundary slowdown
		"ADD", // opcode
		NULL // function
	);
	//ASL instructions
	instructions[0x0A] = nes_instruction(
		2, // time
		MODE_NOTHING, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"ASL", // opcode
		NULL // function
	);
	instructions[0x06] = nes_instruction(
		5, // time
		MODE_ZEROPAGE, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"ASL", // opcode
		NULL // function
	);
	instructions[0x16] = nes_instruction(
		6, // time
		MODE_ZEROPAGEX, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"ASL", // opcode
		NULL // function
	);
	instructions[0x0E] = nes_instruction(
		6, // time
		MODE_ABSOLUTE, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"ASL", // opcode
		NULL // function
	);
	instructions[0x1E] = nes_instruction(
		7, // time
		MODE_ABSOLUTEX, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"ASL", // opcode
		NULL // function
	);
	//BIT instructions
	instructions[0x24] = nes_instruction(
		3, // time
		MODE_ZEROPAGE, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"BIT", // opcode
		NULL // function
	);
	instructions[0x2C] = nes_instruction(
		4, // time
		MODE_ABSOLUTE, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"BIT", // opcode
		NULL // function
	);
	//Branch instructions (Bxx)
	instructions[0x10] = nes_instruction(
		2, // time
		MODE_RELATIVE, // mode
		NULL, // pram 2
		true, // page boundary slowdown
		"BPL", // opcode
		NULL // function
	);
	instructions[0x30] = nes_instruction(
		2, // time
		MODE_RELATIVE, // mode
		NULL, // pram 2
		true, // page boundary slowdown
		"BMI", // opcode
		NULL // function
	);
	instructions[0x50] = nes_instruction(
		2, // time
		MODE_RELATIVE, // mode
		NULL, // pram 2
		true, // page boundary slowdown
		"BVC", // opcode
		NULL // function
	);
	instructions[0x70] = nes_instruction(
		2, // time
		MODE_RELATIVE, // mode
		NULL, // pram 2
		true, // page boundary slowdown
		"BVS", // opcode
		NULL // function
	);
	instructions[0x90] = nes_instruction(
		2, // time
		MODE_RELATIVE, // mode
		NULL, // pram 2
		true, // page boundary slowdown
		"BCC", // opcode
		NULL // function
	);
	instructions[0xB0] = nes_instruction(
		2, // time
		MODE_RELATIVE, // mode
		NULL, // pram 2
		true, // page boundary slowdown
		"BCS", // opcode
		NULL // function
	);
	instructions[0xD0] = nes_instruction(
		2, // time
		MODE_RELATIVE, // mode
		NULL, // pram 2
		true, // page boundary slowdown
		"BNE", // opcode
		NULL // function
	);
	instructions[0xF0] = nes_instruction(
		2, // time
		MODE_RELATIVE, // mode
		NULL, // pram 2
		true, // page boundary slowdown
		"BEQ", // opcode
		NULL // function
	);
	//BRK instruction
	instructions[0x00] = nes_instruction(
		7, // time
		MODE_NOTHING, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"BRK", // opcode
		NULL // function
	);
	//CMP instructions
	instructions[0xC9] = nes_instruction(
		2, // time
		MODE_IMMEDIATE, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"CMP", // opcode
		NULL // function
	);
	instructions[0xC5] = nes_instruction(
		3, // time
		MODE_ZEROPAGE, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"CMP", // opcode
		NULL // function
	);
	instructions[0xD5] = nes_instruction(
		4, // time
		MODE_ZEROPAGEX, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"CMP", // opcode
		NULL // function
	);
	instructions[0xCD] = nes_instruction(
		4, // time
		MODE_ABSOLUTE, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"CMP", // opcode
		NULL // function
	);
	instructions[0xDD] = nes_instruction(
		4, // time
		MODE_ABSOLUTEX, // mode
		&reg_a, // pram 2
		true, // page boundary slowdown
		"CMP", // opcode
		NULL // function
	);
	instructions[0xD9] = nes_instruction(
		4, // time
		MODE_ABSOLUTEY, // mode
		&reg_a, // pram 2
		true, // page boundary slowdown
		"CMP", // opcode
		NULL // function
	);
	instructions[0xC1] = nes_instruction(
		6, // time
		MODE_INDIRECTX, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"CMP", // opcode
		NULL // function
	);
	instructions[0xD1] = nes_instruction(
		5, // time
		MODE_INDIRECTY, // mode
		&reg_a, // pram 2
		true, // page boundary slowdown
		"CMP", // opcode
		NULL // function
	);
	//CPX instructions
	instructions[0xE0] = nes_instruction(
		2, // time
		MODE_IMMEDIATE, // mode
		&reg_x, // pram 2
		false, // page boundary slowdown
		"CPX", // opcode
		NULL // function
	);
	instructions[0xE4] = nes_instruction(
		3, // time
		MODE_ZEROPAGE, // mode
		&reg_x, // pram 2
		false, // page boundary slowdown
		"CPX", // opcode
		NULL // function
	);
	instructions[0xEC] = nes_instruction(
		4, // time
		MODE_ABSOLUTE, // mode
		&reg_x, // pram 2
		false, // page boundary slowdown
		"CPX", // opcode
		NULL // function
	);
	//CPY instructions
	instructions[0xC0] = nes_instruction(
		2, // time
		MODE_IMMEDIATE, // mode
		&reg_y, // pram 2
		false, // page boundary slowdown
		"CPY", // opcode
		NULL // function
	);
	instructions[0xC4] = nes_instruction(
		3, // time
		MODE_ZEROPAGE, // mode
		&reg_y, // pram 2
		false, // page boundary slowdown
		"CPY", // opcode
		NULL // function
	);
	instructions[0xCC] = nes_instruction(
		4, // time
		MODE_ABSOLUTE, // mode
		&reg_y, // pram 2
		false, // page boundary slowdown
		"CPY", // opcode
		NULL // function
	);
	//DEC instructions
	instructions[0xC6] = nes_instruction(
		5, // time
		MODE_ZEROPAGE, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"DEC", // opcode
		NULL // function
	);
	instructions[0xD6] = nes_instruction(
		6, // time
		MODE_ZEROPAGEX, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"DEC", // opcode
		NULL // function
	);
	instructions[0xCE] = nes_instruction(
		6, // time
		MODE_ABSOLUTE, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"DEC", // opcode
		NULL // function
	);
	instructions[0xDE] = nes_instruction(
		7, // time
		MODE_ABSOLUTEX, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"DEC", // opcode
		NULL // function
	);
	//EOR instructions
	instructions[0x49] = nes_instruction(
		2, // time
		MODE_IMMEDIATE, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"EOR", // opcode
		NULL // function
	);
	instructions[0x45] = nes_instruction(
		3, // time
		MODE_ZEROPAGE, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"EOR", // opcode
		NULL // function
	);
	instructions[0x55] = nes_instruction(
		4, // time
		MODE_ZEROPAGEX, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"EOR", // opcode
		NULL // function
	);
	instructions[0x4D] = nes_instruction(
		4, // time
		MODE_ABSOLUTE, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"EOR", // opcode
		NULL // function
	);
	instructions[0x5D] = nes_instruction(
		4, // time
		MODE_ABSOLUTEX, // mode
		&reg_a, // pram 2
		true, // page boundary slowdown
		"EOR", // opcode
		NULL // function
	);
	instructions[0x59] = nes_instruction(
		4, // time
		MODE_ABSOLUTEY, // mode
		&reg_a, // pram 2
		true, // page boundary slowdown
		"EOR", // opcode
		NULL // function
	);
	instructions[0x41] = nes_instruction(
		6, // time
		MODE_INDIRECTX, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"EOR", // opcode
		NULL // function
	);
	instructions[0x51] = nes_instruction(
		5, // time
		MODE_INDIRECTY, // mode
		&reg_a, // pram 2
		true, // page boundary slowdown
		"EOR", // opcode
		NULL // function
	);
	//Flag instructions
	instructions[0x18] = nes_instruction(
		2, // time
		MODE_NOTHING, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"CLC", // opcode
		NULL // function
	);
	instructions[0x38] = nes_instruction(
		2, // time
		MODE_NOTHING, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"SEC", // opcode
		NULL // function
	);
	instructions[0x58] = nes_instruction(
		2, // time
		MODE_NOTHING, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"CLI", // opcode
		NULL // function
	);
	instructions[0x78] = nes_instruction(
		2, // time
		MODE_NOTHING, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"SEI", // opcode
		NULL // function
	);
	instructions[0xB8] = nes_instruction(
		2, // time
		MODE_NOTHING, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"CLV", // opcode
		NULL // function
	);
	instructions[0xD8] = nes_instruction(
		2, // time
		MODE_NOTHING, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"CLD", // opcode
		NULL // function
	);
	instructions[0xF8] = nes_instruction(
		2, // time
		MODE_NOTHING, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"SED", // opcode
		NULL // function
	);
	//INC instructions
	instructions[0xE6] = nes_instruction(
		5, // time
		MODE_ZEROPAGE, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"INC", // opcode
		NULL // function
	);
	instructions[0xF6] = nes_instruction(
		6, // time
		MODE_ZEROPAGEX, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"INC", // opcode
		NULL // function
	);
	instructions[0xEE] = nes_instruction(
		6, // time
		MODE_ABSOLUTE, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"INC", // opcode
		NULL // function
	);
	instructions[0xFE] = nes_instruction(
		7, // time
		MODE_ABSOLUTEX, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"INC", // opcode
		NULL // function
	);
	//JMP instructions
	instructions[0x4C] = nes_instruction(
		3, // time
		MODE_ABSOLUTE, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"JMP", // opcode
		NULL // function
	);
	instructions[0xFC] = nes_instruction(
		5, // time
		MODE_INDIRECT, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"JMP", // opcode
		NULL // function
	);
	//JSR instruction
	instructions[0x20] = nes_instruction(
		6, // time
		MODE_ABSOLUTE, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"JSR", // opcode
		NULL // function
	);
	//LDA instructions
	instructions[0xA9] = nes_instruction(
		2, // time
		MODE_IMMEDIATE, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"LDA", // opcode
		NULL // function
	);
	instructions[0xA5] = nes_instruction(
		3, // time
		MODE_ZEROPAGE, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"LDA", // opcode
		NULL // function
	);
	instructions[0xB5] = nes_instruction(
		4, // time
		MODE_ZEROPAGEX, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"LDA", // opcode
		NULL // function
	);
	instructions[0xAD] = nes_instruction(
		4, // time
		MODE_ABSOLUTE, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"LDA", // opcode
		NULL // function
	);
	instructions[0xBD] = nes_instruction(
		4, // time
		MODE_ABSOLUTEX, // mode
		&reg_a, // pram 2
		true, // page boundary slowdown
		"LDA", // opcode
		NULL // function
	);
	instructions[0xB9] = nes_instruction(
		4, // time
		MODE_ABSOLUTEY, // mode
		&reg_a, // pram 2
		true, // page boundary slowdown
		"LDA", // opcode
		NULL // function
	);
	instructions[0xA1] = nes_instruction(
		6, // time
		MODE_INDIRECTX, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"LDA", // opcode
		NULL // function
	);
	instructions[0xB1] = nes_instruction(
		5, // time
		MODE_INDIRECTY, // mode
		&reg_a, // pram 2
		true, // page boundary slowdown
		"LDA", // opcode
		NULL // function
	);
	//LDX instructions
	instructions[0xA2] = nes_instruction(
		2, // time
		MODE_IMMEDIATE, // mode
		&reg_x, // pram 2
		false, // page boundary slowdown
		"LDX", // opcode
		NULL // function
	);
	instructions[0xA6] = nes_instruction(
		3, // time
		MODE_ZEROPAGE, // mode
		&reg_x, // pram 2
		false, // page boundary slowdown
		"LDX", // opcode
		NULL // function
	);
	instructions[0xB6] = nes_instruction(
		4, // time
		MODE_ZEROPAGEY, // mode
		&reg_x, // pram 2
		false, // page boundary slowdown
		"LDX", // opcode
		NULL // function
	);
	instructions[0xAE] = nes_instruction(
		4, // time
		MODE_ABSOLUTE, // mode
		&reg_x, // pram 2
		false, // page boundary slowdown
		"LDX", // opcode
		NULL // function
	);
	instructions[0xBE] = nes_instruction(
		4, // time
		MODE_ABSOLUTEY, // mode
		&reg_x, // pram 2
		true, // page boundary slowdown
		"LDX", // opcode
		NULL // function
	);
	//LDY instructions
	instructions[0xA0] = nes_instruction(
		2, // time
		MODE_IMMEDIATE, // mode
		&reg_y, // pram 2
		false, // page boundary slowdown
		"LDY", // opcode
		NULL // function
	);
	instructions[0xA4] = nes_instruction(
		3, // time
		MODE_ZEROPAGE, // mode
		&reg_y, // pram 2
		false, // page boundary slowdown
		"LDY", // opcode
		NULL // function
	);
	instructions[0xB4] = nes_instruction(
		4, // time
		MODE_ZEROPAGEX, // mode
		&reg_y, // pram 2
		false, // page boundary slowdown
		"LDY", // opcode
		NULL // function
	);
	instructions[0xAC] = nes_instruction(
		4, // time
		MODE_ABSOLUTE, // mode
		&reg_y, // pram 2
		false, // page boundary slowdown
		"LDY", // opcode
		NULL // function
	);
	instructions[0xBC] = nes_instruction(
		4, // time
		MODE_ABSOLUTEX, // mode
		&reg_y, // pram 2
		true, // page boundary slowdown
		"LDY", // opcode
		NULL // function
	);
	//LSR instructions
	instructions[0x4A] = nes_instruction(
		2, // time
		MODE_NOTHING, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"LSR", // opcode
		NULL // function
	);
	instructions[0x46] = nes_instruction(
		5, // time
		MODE_ZEROPAGE, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"LSR", // opcode
		NULL // function
	);
	instructions[0x56] = nes_instruction(
		6, // time
		MODE_ZEROPAGEX, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"LSR", // opcode
		NULL // function
	);
	instructions[0x4E] = nes_instruction(
		6, // time
		MODE_ABSOLUTE, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"LSR", // opcode
		NULL // function
	);
	instructions[0x5E] = nes_instruction(
		7, // time
		MODE_ABSOLUTEX, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"LSR", // opcode
		NULL // function
	);
	//ORA instructions
	instructions[0x09] = nes_instruction(
		2, // time
		MODE_IMMEDIATE, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"ORA", // opcode
		NULL // function
	);
	instructions[0x05] = nes_instruction(
		2, // time
		MODE_ZEROPAGE, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"ORA", // opcode
		NULL // function
	);
	instructions[0x15] = nes_instruction(
		3, // time
		MODE_ZEROPAGEX, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"ORA", // opcode
		NULL // function
	);
	instructions[0x0D] = nes_instruction(
		4, // time
		MODE_ABSOLUTE, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"ORA", // opcode
		NULL // function
	);
	instructions[0x1D] = nes_instruction(
		4, // time
		MODE_ABSOLUTEX, // mode
		&reg_a, // pram 2
		true, // page boundary slowdown
		"ORA", // opcode
		NULL // function
	);
	instructions[0x19] = nes_instruction(
		4, // time
		MODE_ABSOLUTEY, // mode
		&reg_a, // pram 2
		true, // page boundary slowdown
		"ORA", // opcode
		NULL // function
	);
	instructions[0x01] = nes_instruction(
		6, // time
		MODE_INDIRECTX, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"ORA", // opcode
		NULL // function
	);
	instructions[0x11] = nes_instruction(
		5, // time
		MODE_INDIRECTY, // mode
		&reg_a, // pram 2
		true, // page boundary slowdown
		"ORA", // opcode
		NULL // function
	);
	//Register instructions
	instructions[0xAA] = nes_instruction(
		2, // time
		MODE_NOTHING, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"TAX", // opcode
		NULL // function
	);
	instructions[0x8A] = nes_instruction(
		2, // time
		MODE_NOTHING, // mode
		&reg_x, // pram 2
		false, // page boundary slowdown
		"TXA", // opcode
		NULL // function
	);
	instructions[0xCA] = nes_instruction(
		2, // time
		MODE_NOTHING, // mode
		&reg_x, // pram 2
		false, // page boundary slowdown
		"DEX", // opcode
		NULL // function
	);
	instructions[0xE8] = nes_instruction(
		2, // time
		MODE_NOTHING, // mode
		&reg_x, // pram 2
		false, // page boundary slowdown
		"INX", // opcode
		NULL // function
	);
	instructions[0xA8] = nes_instruction(
		2, // time
		MODE_NOTHING, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"TAY", // opcode
		NULL // function
	);
	instructions[0x98] = nes_instruction(
		2, // time
		MODE_NOTHING, // mode
		&reg_y, // pram 2
		false, // page boundary slowdown
		"TYA", // opcode
		NULL // function
	);
	instructions[0x88] = nes_instruction(
		2, // time
		MODE_NOTHING, // mode
		&reg_y, // pram 2
		false, // page boundary slowdown
		"DEY", // opcode
		NULL // function
	);
	instructions[0xC8] = nes_instruction(
		2, // time
		MODE_NOTHING, // mode
		&reg_y, // pram 2
		false, // page boundary slowdown
		"INY", // opcode
		NULL // function
	);
	//ROL instructions
	instructions[0x2A] = nes_instruction(
		2, // time
		MODE_NOTHING, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"ROL", // opcode
		NULL // function
	);
	instructions[0x26] = nes_instruction(
		5, // time
		MODE_ZEROPAGE, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"ROL", // opcode
		NULL // function
	);
	instructions[0x36] = nes_instruction(
		6, // time
		MODE_ZEROPAGEX, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"ROL", // opcode
		NULL // function
	);
	instructions[0x2E] = nes_instruction(
		6, // time
		MODE_ABSOLUTE, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"ROL", // opcode
		NULL // function
	);
	instructions[0x3E] = nes_instruction(
		7, // time
		MODE_ABSOLUTEX, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"ROL", // opcode
		NULL // function
	);
	//ROR instructions
	instructions[0x6A] = nes_instruction(
		2, // time
		MODE_NOTHING, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"ROR", // opcode
		NULL // function
	);
	instructions[0x66] = nes_instruction(
		5, // time
		MODE_ZEROPAGE, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"ROR", // opcode
		NULL // function
	);
	instructions[0x76] = nes_instruction(
		6, // time
		MODE_ZEROPAGEX, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"ROR", // opcode
		NULL // function
	);
	instructions[0x6E] = nes_instruction(
		6, // time
		MODE_ABSOLUTE, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"ROR", // opcode
		NULL // function
	);
	instructions[0x7E] = nes_instruction(
		7, // time
		MODE_ABSOLUTEX, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"ROR", // opcode
		NULL // function
	);
	//RTI instruction
	instructions[0x40] = nes_instruction(
		6, // time
		MODE_NOTHING, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"RTI", // opcode
		NULL // function
	);
	//RTS instruction
	instructions[0x60] = nes_instruction(
		6, // time
		MODE_NOTHING, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"RTS", // opcode
		NULL // function
	);
	//SBC instructions
	instructions[0xE9] = nes_instruction(
		2, // time
		MODE_IMMEDIATE, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"SBC", // opcode
		NULL // function
	);
	instructions[0xE5] = nes_instruction(
		3, // time
		MODE_ZEROPAGE, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"SBC", // opcode
		NULL // function
	);
	instructions[0xF5] = nes_instruction(
		4, // time
		MODE_ZEROPAGEX, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"SBC", // opcode
		NULL // function
	);
	instructions[0xED] = nes_instruction(
		4, // time
		MODE_ABSOLUTE, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"SBC", // opcode
		NULL // function
	);
	instructions[0xFD] = nes_instruction(
		4, // time
		MODE_ABSOLUTEX, // mode
		&reg_a, // pram 2
		true, // page boundary slowdown
		"SBC", // opcode
		NULL // function
	);
	instructions[0xF9] = nes_instruction(
		4, // time
		MODE_ABSOLUTEY, // mode
		&reg_a, // pram 2
		true, // page boundary slowdown
		"SBC", // opcode
		NULL // function
	);
	instructions[0xE1] = nes_instruction(
		6, // time
		MODE_INDIRECTX, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"SBC", // opcode
		NULL // function
	);
	instructions[0xF1] = nes_instruction(
		5, // time
		MODE_INDIRECTY, // mode
		&reg_a, // pram 2
		true, // page boundary slowdown
		"SBC", // opcode
		NULL // function
	);
	//STA instructions
	instructions[0x85] = nes_instruction(
		3, // time
		MODE_ZEROPAGE, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"STA", // opcode
		NULL // function
	);
	instructions[0x95] = nes_instruction(
		4, // time
		MODE_ZEROPAGEX, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"STA", // opcode
		NULL // function
	);
	instructions[0x8D] = nes_instruction(
		4, // time
		MODE_ABSOLUTE, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"STA", // opcode
		NULL // function
	);
	instructions[0x9D] = nes_instruction(
		5, // time
		MODE_ABSOLUTEX, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"STA", // opcode
		NULL // function
	);
	instructions[0x99] = nes_instruction(
		5, // time
		MODE_ABSOLUTEY, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"STA", // opcode
		NULL // function
	);
	instructions[0x81] = nes_instruction(
		6, // time
		MODE_INDIRECTX, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"STA", // opcode
		NULL // function
	);
	instructions[0x91] = nes_instruction(
		6, // time
		MODE_INDIRECTY, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"STA", // opcode
		NULL // function
	);
	//Stack instructions
	instructions[0x9A] = nes_instruction(
		2, // time
		MODE_NOTHING, // mode
		&reg_x, // pram 2
		false, // page boundary slowdown
		"TXS", // opcode
		NULL // function
	);
	instructions[0xBA] = nes_instruction(
		2, // time
		MODE_NOTHING, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"TSX", // opcode
		NULL // function
	);
	instructions[0x48] = nes_instruction(
		3, // time
		MODE_NOTHING, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"PHA", // opcode
		NULL // function
	);
	instructions[0x68] = nes_instruction(
		4, // time
		MODE_NOTHING, // mode
		&reg_a, // pram 2
		false, // page boundary slowdown
		"PLA", // opcode
		NULL // function
	);
	instructions[0x08] = nes_instruction(
		3, // time
		MODE_NOTHING, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"PHP", // opcode
		NULL // function
	);
	instructions[0x28] = nes_instruction(
		4, // time
		MODE_NOTHING, // mode
		NULL, // pram 2
		false, // page boundary slowdown
		"PLP", // opcode
		NULL // function
	);
	//STX instructions
	instructions[0x86] = nes_instruction(
		3, // time
		MODE_ZEROPAGE, // mode
		&reg_x, // pram 2
		false, // page boundary slowdown
		"STX", // opcode
		NULL // function
	);
	instructions[0x96] = nes_instruction(
		4, // time
		MODE_ZEROPAGEY, // mode
		&reg_x, // pram 2
		false, // page boundary slowdown
		"STX", // opcode
		NULL // function
	);
	instructions[0x8E] = nes_instruction(
		4, // time
		MODE_ABSOLUTE, // mode
		&reg_x, // pram 2
		false, // page boundary slowdown
		"STX", // opcode
		NULL // function
	);
	//STY instructions
	instructions[0x84] = nes_instruction(
		3, // time
		MODE_ZEROPAGE, // mode
		&reg_y, // pram 2
		false, // page boundary slowdown
		"STY", // opcode
		NULL // function
	);
	instructions[0x94] = nes_instruction(
		4, // time
		MODE_ZEROPAGEX, // mode
		&reg_y, // pram 2
		false, // page boundary slowdown
		"STY", // opcode
		NULL // function
	);
	instructions[0x8C] = nes_instruction(
		4, // time
		MODE_ABSOLUTE, // mode
		&reg_y, // pram 2
		false, // page boundary slowdown
		"STY", // opcode
		NULL // function
	);

	return 0;
}
