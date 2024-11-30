#include "constant.h"

 // Add class Constant member functions implementation

 /*
 * Note: non-pure virtual functions must be implemented, even if they are not called;
 * otherwise, a linker error will be generated.
 * If an implementation is not yet ready, a function stub can be used as a placeholder.
 */

//skriv aldrig override i cpp file


Constant::Constant() : Expression() {

	value = 0.0;
}

Constant::Constant(const double x) : Expression() {

	value = x;
}

double Constant::evaluate() const {
	return value;
}

void Constant::display(std::ostream& os) const {
	os << evaluate();
}

Expression* Constant::clone() const {
	return new Constant(*this);
}

