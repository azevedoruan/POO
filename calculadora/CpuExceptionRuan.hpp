#ifndef CPU_EXCEPTION_H
#define CPU_EXCEPTION_H

#include "Calculator.hpp"

class CpuExceptionRuan : public CalculatorError {
public:
    CpuExceptionRuan(char const*);
    virtual char const *getMessage();
};

#endif