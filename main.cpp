#include <cstddef>

#include "nes_instruction.h"

// define registers
unsigned short int reg_a = 0;
unsigned short int reg_x = 0;
unsigned short int reg_y = 0;

int main() {
	// define instructions
	nes_instruction instructions[256];
	//ADC instructions
	instructions[0x69] = nes_instruction(
		2,
		4,
		&reg_a,
		false,
		"ADC",
		NULL
	);

	return 0;
}
