#include "Calculator.hpp"

CalculatorError::CalculatorError(char const* message) {
    this->message = message;
}

char const* CalculatorError::getMessage() {
    return this->message;
}