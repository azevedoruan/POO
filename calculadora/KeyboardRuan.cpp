#include "KeyboardRuan.hpp"

void KeyboardRuan::receive(Digit digit) {
    if (cpu)
        cpu->receive(digit);
    else
        throw CalculatorError("Keyboard without cpu!");
}

void KeyboardRuan::receive(Operator op) {
    if (cpu)
        cpu->receive(op);
    else
        throw CalculatorError("Keyboard without cpu!");
}

void KeyboardRuan::receive(Control control) {
    if (cpu)
        cpu->receive(control);
    else
        throw CalculatorError("Keyboard without cpu!");
}

Key *KeyboardRuan::getKey(Digit digit) {
    for (Key *key : keys)
        if (dynamic_cast<KeyDigit *>(key) && ((KeyDigit *)key)->getDigit() == digit)
            return key;
    throw CalculatorError("Key with digit not found!");
}

Key *KeyboardRuan::getKey(Operator operator_) {
    for (Key *key : keys)
        if (dynamic_cast<KeyOperator *>(key) && ((KeyOperator *)key)->getOperator() == operator_)
            return key;
    throw CalculatorError("Key with operator not found!");
}

Key *KeyboardRuan::getKey(Control control) {
    for (Key *key : keys)
        if (dynamic_cast<KeyControl *>(key) && ((KeyControl *)key)->getControl() == control)
            return key;
    throw CalculatorError("Key with control not found!");
}

Key *KeyboardRuan::getKey(Symbol symbol) {
    for (Key *key : keys)
        if (key->getSymbol() == symbol)
            return key;
    throw CalculatorError("Key with symbol not found!");
}

void KeyboardRuan::add(Key *key) {
    if (key != 0) {
        keys.push_back(key);
        key->setKeyboard(this);
    }
}

void KeyboardRuan::setCpu(Cpu *cpu) {
    this->cpu = cpu;
}
