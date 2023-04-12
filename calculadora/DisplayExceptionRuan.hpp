#ifndef DISPLAY_EXCEPTION_H
#define DISPLAY_EXCEPTION_H

#include "Calculator.hpp"

class DisplayExceptionRuan : public CalculatorError {
public:
    DisplayExceptionRuan(char const*);
    virtual char const *getMessage();
};

#endif