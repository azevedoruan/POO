#ifndef DISPLAY_H
#define DISPLAY_H

#include<stdio.h>

#include "Calculator.hpp"
#include "Console.hpp"

#define MAX_CHARACTERS 8

class DisplayRuan : public Display {
private:
    char currentPos;
    Digit digits[MAX_CHARACTERS];
    void printDigit(int, char const*, char const*, char const*, char const*, char const*);
public:
    DisplayRuan();
    ~DisplayRuan();
    void addDigit(Digit);
    void setSignal(Signal);
    void addDecimalSeparator();
    void clear();
};

#endif