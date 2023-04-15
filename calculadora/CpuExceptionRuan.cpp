#include "CpuExceptionRuan.hpp"

CpuExceptionRuan::CpuExceptionRuan(char const* message) : CalculatorError(message) {
    
}

char const* CpuExceptionRuan::getMessage() {
    return this->message;
}