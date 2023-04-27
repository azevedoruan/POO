#ifndef CPU_H
#define CPU_H

#include <stdio.h> // para fins de teste !!!
#include <math.h>

#include "Calculator.hpp"

#define MAX_CHARACTERS 8

class CpuRuan : public Cpu {
private:
    Display* display;
    Digit a[MAX_CHARACTERS];
    Digit b[MAX_CHARACTERS];
    int aCount = 0;
    int bCount = 0;
    Signal currentSignal = Signal::POSITIVE;
    Operator currentOperator;
    bool operatorDefined = false;
    void addDigitInExpressionA(Digit);
    void addDigitInExpressionB(Digit);
    void calculateResult();
    int digitToInt(Digit const*, int);
    Digit intToDigit(int, int);

public:
    void receive(Digit);
    void receive(Operator);
    void receive(Control);
    void setDisplay(Display*);
};

#endif