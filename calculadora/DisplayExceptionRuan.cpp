#include "DisplayExceptionRuan.hpp"

DisplayExceptionRuan::DisplayExceptionRuan(char const* message) : CalculatorError(message) {
    
}

char const* DisplayExceptionRuan::getMessage() {
    return this->message;
}