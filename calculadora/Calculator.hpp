#ifndef CALCULATOR_H
#define CALCULATOR_H

/* PRIMEIRA ABSTRAÇÃO DE UMA CALCULADORA */

enum Digit { ZERO = 0, ONE = 1, TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGTH = 8, NINE = 9 };

class Button {
public:
    void press(const char);
};

class Keyboard {
private:
    Button** buttons;
public:
    Button** getButtons();
    Button* findButton(const char);
    void send();
};

class Cpu {
public:
};

class Display {
public:
    virtual void addDigit(Digit) = 0;
    virtual void clear() = 0;
};

/* Responsabilidade: montar uma calculadora */
class Calculator {
private:
    Display* display;
    Cpu* cpu;
    Keyboard* keyboard;
public:
    Calculator();
    Calculator(Display*, Cpu*, Keyboard*);
    ~Calculator();
};

#endif