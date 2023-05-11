#pragma once
#include "Calculator.hpp"
#include "Console.hpp"
class DisplayElias : public Display{
    private:
        unsigned char digitsCount;
    public:
    DisplayElias();
    void add(Digit);
    void addDecimalSeparator();
    void clear();
    void setSignal(Signal);
};