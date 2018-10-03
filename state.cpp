#include "state.h"

unsigned short int reg_dummy;

state::state() {
	this->reg_a = 0;
	this->reg_x = 0;
	this->reg_y = 0;
}

unsigned short int * state::get_reg(char reg) {
	switch(reg) {
		case 'a': return &reg_a;
		case 'x': return &reg_x;
		case 'y': return &reg_y;
	}
	return &reg_dummy;
}
void state::set_reg(char reg, unsigned short int val) {
	switch(reg) {
		case 'a': reg_a = val;
		case 'x': reg_x = val;
		case 'y': reg_y = val;
	}
}
