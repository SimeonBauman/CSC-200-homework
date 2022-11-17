#include <iostream>
#include "classHolder.hpp"

int dice::roll() {
	
	return rand() % sides + 1;
}

dice::dice(int s) {
	sides = s;
}