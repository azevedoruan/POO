#ifndef CALCULATOR_H
#define CALCULATOR_H

/* PRIMEIRA ABSTRAÇÃO DE UMA CALCULADORA */

enum Digit { ZERO = 0, ONE = 1, TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGTH = 8, NINE = 9 };
enum Operator {SUM, SUBTRACTION, DIVISION, MULTIPLICATION};
enum Control {EQUAL, DECIMAL_SEPARATOR, CLEAR_ERROR, OFF, MEMORY_READ_CLEAR, MEMORY_SUM, MEMORY_SUBTRACTION};

class Key {
public:
    virtual void press(const char) = 0;
    virtual char const* getSymbol() = 0;
    virtual Digit getDigit() = 0;
};

class Keyboard {
public:
    virtual void receive(Digit) = 0;
};

class Cpu {
public:
    virtual void receive(Digit) = 0;
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

class CalculatorError {
protected:
    char const* message;
public:
    CalculatorError(char const*);
    virtual char const* getMessage();
};

#endif