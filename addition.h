#pragma once

#include <iostream>

#include "expression.h"

class Addition : public Expression {
public:
	Addition();

	Addition(const Expression& ex1, const Expression& ex2);

	double evaluate() const override;

	Expression* clone() const override;

protected:
	void display(std::ostream& os) const override;

private:

	Expression* e1;

	Expression* e2;

	double value;

};