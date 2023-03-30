#include "Calculator.hpp"
#include "DisplayRuan.hpp"

void calculatorTest() {

    DisplayRuan d1;
    d1.addDigit(Digit::ZERO);
    d1.addDigit(Digit::ONE);
    d1.addDigit(Digit::TWO);
}

int main() {

    calculatorTest();

    return 0;
}