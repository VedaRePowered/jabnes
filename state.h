#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include <cstddef>

#include "nes_instruction.h"

class state{
public:
	state();
	unsigned short int * get_reg(char reg);
	void set_reg(char reg, unsigned short int val);
private:
	unsigned short int reg_a;
	unsigned short int reg_x;
	unsigned short int reg_y;
};


#endif
