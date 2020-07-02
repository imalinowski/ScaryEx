#pragma once
#include "Box.h"
#include <iostream>
class Level {
public:

	int b = 0;
	int m = 0;
	int s = 0;

	void set(int _b, int _m, int _s) {
		b = _b;
		m = _m;
		s = _s;
	}
	void print() {
		std::cout << "Big: " << b << "Medium: " << m << "Small: " << s;
	}
};