#pragma once

#include <iostream>

class Expression {
public:
    // Destructor
    virtual ~Expression() = default;

    // To evaluate an expression
    virtual double evaluate() const = 0;

    // Return a pointer to a copy of *this in the heap
    // Polymorphic copy
    virtual Expression* clone() const = 0;

    // Overloaded stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Expression& e) {
        e.display(os);  // dynamic binding
        return os;
    }

protected:
    // Default constructor
    Expression() = default;

    // Copy constructor
    Expression(const Expression&) = default;

    // Assignment operator
    Expression& operator=(const Expression&) = default;

    virtual void display(std::ostream&) const = 0;
};
