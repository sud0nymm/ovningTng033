#include <iostream>
#include <vector>

#include "constant.h"
#include "power.h"
#include "addition.h"

int main() {
    std::cout << "Phase 0 ...\n";

    Constant* ptr1 = new Constant{5.0};           // 5
    Power* ptr2 = new Power{2, 10};               // 2^10
    Addition* ptr3 = new Addition{*ptr1, *ptr2};  // (5 + 2^10)

    std::vector<Expression*> exps = {ptr1, ptr2, ptr3};

    for (const Expression* ptr : exps) {
        std::cout << *ptr << '\n';
    }

    /* **************************************** */
    std::cout << "\nPhase 1 ...\n";

    /* Test constructors and assignment operators */
    Constant c{*ptr1};
    Power p1{*ptr2};
    Power p2{3, 6};  // 3^6
    Addition ad1{*ptr3};
    Addition ad2{p2, Constant{3}};  // 3^6 + 3

    std::cout << "c = " << c << "\n";
    std::cout << "p1 = " << p1 << "\n";
    std::cout << "p2 = " << p2 << "\n";
    std::cout << "ad1 = " << ad1 << "\n";
    std::cout << "ad2 = " << ad2 << "\n";

    std::cout << "\n";

    // c = c; // should not compile -- it's a constant
    p1 = p2;
    std::cout << "p1 = " << p1 << "\n";

    ad1 = ad2;
    std::cout << "ad1 = " << ad1 << "\n";

    // p1 = ad1;  // should not compile
    // ad1 = p1;  // should not compile

    /* **************************************** */
    std::cout << "\nPhase 2 ...\n";

    // Modify a power expression
    ptr2->set_exponent(8);

    // Create some more expressions
    Addition* ptr4 = new Addition{Constant{4.2}, Constant{6.6}};  // (4.2 + 6.6)
    Addition* ptr5 = new Addition{*ptr2, *ptr4};                  // ((5 + 2^8) + (4.2 + 6.6))

    // Add expressions to the vector
    exps.push_back(ptr4);
    exps.push_back(ptr5);

    for (const Expression* ptr : exps) {
        std::cout << *ptr << "= " << ptr->evaluate() << '\n';
    }

    /* **************************************** */
     std::cout << "\nPhase 3 ...\n";

    // Free dynamically allocated memory
    for (Expression* ptr : exps) {
        delete ptr;
    }
}
