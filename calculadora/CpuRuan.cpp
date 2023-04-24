#include "CpuRuan.hpp"

void CpuRuan::receive(Digit digit) {
    if (operatorDefined == false) {
        addDigitInExpressionA(digit);
    } else {
        if (bCount == 0)
            display->clear();
        addDigitInExpressionB(digit);
    }
}

void CpuRuan::receive(Operator op) {
    currentOperator = op;
    if (operatorDefined)
        calculateResult();
    else
        operatorDefined = true;
}

void CpuRuan::receive(Control control) {
    switch (control) {
    case Control::EQUAL:
        calculateResult();
        break;
    default:
        throw CalculatorError("Caractere de controle nao reconhecido");
    }
}

void CpuRuan::setDisplay(Display* display) {
    this->display = display;
}

void CpuRuan::addDigitInExpressionA(Digit digit) {
    if (aCount == 0 && digit == Digit::ZERO)
        return;

    if (aCount < MAX_CHARACTERS) {
        a[aCount++] = digit;
        display->addDigit(digit);
    }
}

void CpuRuan::addDigitInExpressionB(Digit digit) {
    if (bCount == 0 && digit == Digit::ZERO)
        return;

    if (bCount < MAX_CHARACTERS) {
        b[bCount++] = digit;
        display->addDigit(digit);
    }
}

void CpuRuan::calculateResult() {

    int numA = digitToInt(a, aCount);
    int numB = digitToInt(b, bCount);
    int result = 0;

    switch (currentOperator) {
    case Operator::SUM: 
        result = numA + numB;
        break;
    case Operator::SUBTRACTION: 
        result = numA - numB;
        break;
    case Operator::MULTIPLICATION: 
        result = numA * numB;
        break;
    case Operator::DIVISION:
        result = numA / numB;
        break;
    default:
        throw CalculatorError("Caractere operador nao reconhecido");
    }

    aCount = 0;
    bCount = 0;
    display->clear();
    for (int i = MAX_CHARACTERS - 1; i >= 0; i--)
        addDigitInExpressionA(intToDigit(result, i));
}

int CpuRuan::digitToInt(Digit const* digits, int count) {
    int num = 0;
    int power = count - 1;
    for (int i = 0; i < count; i++) {
        num += digits[i] * (int)pow(10, power);
        power--;
    }

    return num;
}

Digit CpuRuan::intToDigit(int expression, int index) {
    return Digit((expression / (int)pow(10, index)) % 10);
}