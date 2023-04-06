#include "Calculator.hpp"

class DisplayExceptionRuan : public CalculatorError {
public:
    DisplayExceptionRuan(char const*);
    char const* getMessage();
};