#ifndef DISPLAY_H
#define DISPLAY_H

#include "Calculator.hpp"

#define MAX_CHARACTERS 8

class DisplayRuan : public Display {
private:
    char currentPos;
    Digit digits[MAX_CHARACTERS];
    Signal currentSignal;
    void printDigit(int, char const*, char const*, char const*, char const*, char const*);
    void printSignal();
public:
    DisplayRuan();
    ~DisplayRuan();
    void addDigit(Digit);
    void setSignal(Signal);
    void addDecimalSeparator();
    void clear();
};

#endif