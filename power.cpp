#include <iostream>

#include "power.h"

// Add class Power member functions implementation

/*
* Note: non-pure virtual functions must be implemented, even if they are not called; 
* otherwise, a linker error will be generated. 
* If an implementation is not yet ready, a function stub can be used as a placeholder.
*/

Power::Power() {

	exponent = 0;
	baseValue = 0.0;
	value = 0.0;
}

Power::Power(const double x, const int y) {

	baseValue = x;
	exponent = y;

	if (y == 0) {
		value = 1;
	} else {
		const double baseVal = x;
		double newVal = x;

		for (int i = 1; i < y; i++) {
			newVal = newVal * baseVal;
		}
		value = newVal;
	}
}

Power::Power(const Power& rhs) {
	value = rhs.value;
	baseValue = rhs.baseValue;
	exponent = rhs.exponent;
}

void Power::set_exponent(const int y) {

	Power *p = new Power(baseValue, y);
	*this = *p;
}

// override fncs
double Power::evaluate() const {
	return value;
}

double Power::getBase() {
	return baseValue;
}

int Power::getExpo() {
	return exponent;
}

void Power::display(std::ostream& os) const {
	os << baseValue << "^" << exponent;
}

Expression* Power::clone() const {
	return new Power(*this);
}

Power& Power::operator=(Power rhs) { // assignment operator
	std::swap(value, rhs.value);
	std::swap(baseValue, rhs.baseValue);
	std::swap(exponent, rhs.exponent);
	return *this;
}

