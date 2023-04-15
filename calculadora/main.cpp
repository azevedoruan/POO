#include <string.h>
#include <stdio.h>

#include "Calculator.hpp"
#include "DisplayRuan.hpp"

void calculatorTest()
{
    try
    {
        DisplayRuan d1;
        d1.setSignal(Signal::NEGATIVE);
        d1.addDigit(Digit::ZERO);
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
    catch (CalculatorError e)
    {
        char string[50] = "Erro: ";
        strcat(string, e.getMessage());
        printf("%s\n", string);
    }
}

int main()
{
    calculatorTest();

    return 0;
}