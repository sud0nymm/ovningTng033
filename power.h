#pragma once

#include <iostream>

#include "expression.h"

class Power : public Expression {

public:

	Power();

	Power& operator=(Power rhs);

	Power(const Power& rhs);

	Power(const double x, const int y);

	double evaluate() const override;

	Expression* clone() const override;

	void display(std::ostream&) const override;

	void set_exponent(const int y);

	double getBase();

	int getExpo();

private:

	double baseValue;

	int exponent;

	double value;
};
