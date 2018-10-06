#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <cstddef>

#include "nes_instruction.h"
#include "state.h"

class cpu{
public:
	void execute_instruction(state& current_state, bool debug_mode);
	cpu(void);
private:
	nes_instruction instructions[256];
};

#endif
