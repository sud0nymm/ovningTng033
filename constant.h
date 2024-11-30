#pragma once

#include <iostream>

#include "expression.h"

class Constant : public Expression {
public:

	Constant(); // default constr

	Constant(const double x);

	double evaluate() const override;

	Expression* clone() const override;

	void display(std::ostream&) const override;


private:

	double value;
};

