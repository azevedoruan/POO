#include "KeyRuan.hpp"

/*
    DIGIT
*/
KeyDigitRuan::KeyDigitRuan(Symbol symbol, Digit digit) {
    this->symbol = symbol;
    this->digit = digit;
}

Symbol KeyDigitRuan::getSymbol() {
    return symbol;
}

void KeyDigitRuan::setKeyboard(Keyboard *keyboard) {
    this->keyboard = keyboard;
}

Digit KeyDigitRuan::getDigit() {
    return digit;
}

void KeyDigitRuan::press() {
    if (keyboard != 0)
        keyboard->receive(digit);
}

/*
    CONTROL
*/
KeyControlRuan::KeyControlRuan(Symbol symbol, Control control) {
    this->symbol = symbol;
    this->control = control;
}

Symbol KeyControlRuan::getSymbol() {
    return symbol;
}

void KeyControlRuan::setKeyboard(Keyboard *keyboard) {
    this->keyboard = keyboard;
}

Control KeyControlRuan::getControl() {
    return control;
}

void KeyControlRuan::press() {
    if (keyboard != 0)
        keyboard->receive(control);
}

/*
    OPERATOR
*/
KeyOperatorRuan::KeyOperatorRuan(Symbol symbol, Operator op) {
    this->symbol = symbol;
    this->op = op;
}

Symbol KeyOperatorRuan::getSymbol() {
    return symbol;
}

void KeyOperatorRuan::setKeyboard(Keyboard *keyboard) {
    this->keyboard = keyboard;
}

Operator KeyOperatorRuan::getOperator() {
    return op;
}

void KeyOperatorRuan::press() {
    if (keyboard != 0)
        keyboard->receive(op);
}