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
    if (aCount == 0)
        currentSignal = Signal::NEGATIVE;
   
    if (operatorDefined)
        calculateResult();
    
    operatorDefined = true;
    currentOperator = op;
}

void CpuRuan::receive(Control control) {
    switch (control) {
    case Control::EQUAL:
        if (operatorDefined == true)
            calculateResult();
        break;
    default:
        throw CalculatorError("Control not implemented");
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
        display->add(digit);
    }
}

void CpuRuan::addDigitInExpressionB(Digit digit) {
    if (bCount == 0 && digit == Digit::ZERO)
        return;

    if (bCount < MAX_CHARACTERS) {
        b[bCount++] = digit;
        display->add(digit);
    }
}

void CpuRuan::calculateResult() {
    int numA = digitToInt(a, aCount);
    int numB = digitToInt(b, bCount);
    int result = 0;

    if (currentSignal == Signal::NEGATIVE)
        numA *= -1;

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
        if(numB == 0)
            throw CalculatorError("impossible to divide by zero");
        result = numA / numB;
        break;
    default:
        throw CalculatorError("Operator not implemented");
    }

    aCount = 0;
    bCount = 0;
    display->clear();

    if (result == 0) {
        display->clear();
        return;
    }

    if (result < 0) {
        result *= -1;
        currentSignal = Signal::NEGATIVE;
    } else {
        currentSignal = Signal::POSITIVE;
    }
    
    display->setSignal(currentSignal);

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