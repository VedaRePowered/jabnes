#include <iostream>

#include "instructions.h"
#include "state.h"

int main() {
	std::cout << "+------------------+ JABNES p0.0.1:" << std::endl;
	std::cout << "| J  A  B  N  E  S | - Creator: BEN1JEN" << std::endl;
	std::cout << "| u  n  a  i  m  o | - Licence: GPL 3.0" << std::endl;
	std::cout << "| s  o  s  n  u  f | - Ganra: Emulator" << std::endl;
	std::cout << "| t  t  i  t  l  t | - - System: NES" << std::endl;
	std::cout << "|    h  c  e  a  w | - - Supported ROMs: none" << std::endl;
	std::cout << "|    e     n  t  a | - - Emulated: CPU (kinda)" << std::endl;
	std::cout << "|    r     d  i  r | - Has Base Features: No" << std::endl;
	std::cout << "|          o  o  e | - Build Type: pre-alpha" << std::endl;
	std::cout << "|             n    | - Platforms: Linux" << std::endl;
	std::cout << "+------------------+ - Git Repo: https://gitlab.101100.ca/ben1jen/jabnes" << std::endl;
	std::cout << "\033[53mLog Output:                                                             \033[0m" << std::endl;

	cpu nes_cpu;
	std::cout << "Made CPU class..." << std::endl;
	state current_state;
	std::cout << "Made state class..." << std::endl;
	current_state.load_rom("nestest.nes");
	std::cout << "Loaded ROM: nestest.nes..." << std::endl;
	std::cout << "Executing instructions:" << std::endl;
	for (int i=1; i<8991; i++) {
		nes_cpu.execute_instruction(current_state, true);
	}

	return 0;
}
