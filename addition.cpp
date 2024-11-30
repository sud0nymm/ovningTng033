#include <iostream>

#include "addition.h"

// Add class Addition member functions implementation

/*
 * Note: non-pure virtual functions must be implemented, even if they are not called;
 * otherwise, a linker error will be generated.
 * If an implementation is not yet ready, a function stub can be used as a placeholder.
 */

Addition::Addition() : e1(nullptr), e2(nullptr), value(0) {}


Addition::Addition(const Expression& ex1, const Expression& ex2) {

	e1 = ex1.clone();
	e2 = ex2.clone();

	value = e1->evaluate() + e2->evaluate();
}

double Addition::evaluate() const {
	return value;
}

void Addition::display(std::ostream& os) const {
	os << "(" << *e1 << " + " << *e2 << ")";
}

Expression* Addition::clone() const {
	return new Addition(*this);
}
