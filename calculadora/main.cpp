#include <string.h>
#include <stdio.h>

#include "Calculator.hpp"
#include "DisplayRuan.hpp"
#include "CpuRuan.hpp"

void calculatorTest()
{
    DisplayRuan d1;
    //d1.setSignal(Signal::NEGATIVE);
    /*d1.addDigit(Digit::ZERO);
    d1.addDigit(Digit::ZERO);
    d1.addDigit(Digit::ZERO);
    d1.addDigit(Digit::ZERO);
    d1.addDigit(Digit::ONE);
    d1.addDigit(Digit::TWO);
    d1.addDigit(Digit::ZERO);
    //d1.setSignal(Signal::POSITIVE);
    d1.addDigit(Digit::THREE);
    //d1.addDigit(Digit::FOUR);
    d1.addDigit(Digit::FIVE);
    d1.addDigit(Digit::SIX);
    /*d1.addDigit(Digit::SEVEN);
    d1.addDigit(Digit::EIGTH);
    d1.addDigit(Digit::NINE);*/
   
}

void cpuTest() {
    CpuRuan cpu1;
    DisplayRuan display1;
    cpu1.setDisplay(&display1);

    cpu1.receive(Digit::TWO);
    cpu1.receive(Operator::SUM);
    cpu1.receive(Digit::TWO);
    cpu1.receive(Operator::SUM);
    cpu1.receive(Digit::TWO);
    cpu1.receive(Operator::SUM);
    cpu1.receive(Digit::TWO);
    cpu1.receive(Operator::SUM);
    cpu1.receive(Digit::TWO);
    cpu1.receive(Operator::SUM);
}

int main()
{
    try {
        //calculatorTest();
        cpuTest();
    } catch (CalculatorError e) {
        char string[50] = "Erro: ";
        strcat(string, e.getMessage());
        printf("%s\n", string);
    }

    return 0;
}