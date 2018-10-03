struct nes_instruction {
	short int hex_code; // actuall hex code to look for in ROM
	short int cycles; // number of CPU cycles it takes to execute
	short int address_type; // type of address, 0: Zero Page, 1: Absolute, 2: Immediate, 3: Indirect
	short int * pram_register; // pointer to the register for the second parameter
	bool page_boundary_slowdown = false; // should the instruction take one more cycle if it crosses a page boundary
	char opcode[3]; // opcode name

	void (*execute_function)(short int, short int); // function to execute with two litaral numbers
};
