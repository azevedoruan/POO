#ifndef KEY_H
#define KEY_H

#include "Calculator.hpp"

class KeyDigitRuan : public KeyDigit {
    Symbol symbol;
    Digit digit;
    Keyboard *keyboard;
public:
    KeyDigitRuan(Symbol, Digit);
    Symbol getSymbol();
    void setKeyboard(Keyboard *);
    Digit getDigit();
    void press();
};

class KeyControlRuan : public KeyControl {
    Symbol symbol;
    Control control;
    Keyboard *keyboard;
public:
    KeyControlRuan(Symbol, Control);
    Symbol getSymbol();
    void setKeyboard(Keyboard *);
    Control getControl();
    void press();
};

class KeyOperatorRuan : public KeyOperator {
    Symbol symbol;
    Operator op;
    Keyboard *keyboard;
public:
    KeyOperatorRuan(Symbol, Operator);
    Symbol getSymbol();
    void setKeyboard(Keyboard *);
    Operator getOperator();
    void press();
};

#endif