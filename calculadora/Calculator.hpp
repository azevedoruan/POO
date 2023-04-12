#ifndef CALCULATOR_H
#define CALCULATOR_H

enum Digit { ZERO = 0, ONE = 1, TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGTH = 8, NINE = 9, NULLABLE = 10};
enum Operator { SUM, SUBTRACTION, DIVISION, MULTIPLICATION };
enum Control { EQUAL, DECIMAL_SEPARATOR, CLEAR_ERROR, OFF, MEMORY_READ_CLEAR, MEMORY_SUM, MEMORY_SUBTRACTION };

class Key;
class Keyboard {
   public:
    virtual void receive(Digit) = 0;
    virtual void receive(Operator) = 0;
    virtual void receive(Control) = 0;
    virtual Key *getKey(Digit) = 0;
    virtual Key *getKey(Operator) = 0;
    virtual Key *getKey(Control) = 0;
    virtual void addKey(Key *) = 0;
};

class Key {
   public:
    virtual void press(const char) = 0;
    virtual char const *getSymbol() = 0;
    virtual void setKeyboard(Keyboard *) = 0;
};

class KeyDigit : public Key {
   public:
    virtual Digit getDigit() = 0;
};

class KeyOperator : public Key {
   public:
    virtual Operator getOperator() = 0;
};

class KeyControl : public Key {
   public:
    virtual Control getControl() = 0;
};

class Cpu {
   public:
    virtual void receive(Digit) = 0;
    virtual void receive(Operator) = 0;
    virtual void receive(Control) = 0;
};

class Display {
   public:
    virtual void addDigit(Digit) = 0;
    virtual void addDecimalSeparator() = 0;
    virtual void clear() = 0;
};

/* Responsabilidade: montar uma calculadora */
class Calculator {
   private:
    Display *display;
    Cpu *cpu;
    Keyboard *keyboard;

   public:
    Calculator();
    Calculator(Display *, Cpu *, Keyboard *);
    ~Calculator();
    virtual void setDisplay(Display*) = 0;
    virtual Display* getDisplay() = 0;
    virtual void setCpu(Cpu*) = 0;
    virtual Cpu* getCpu() = 0;
    virtual void setKeyboard(Keyboard*) = 0;
    virtual Keyboard* getKeyboard() = 0;
};

class CalculatorError {
   protected:
    char const *message;

   public:
    CalculatorError(char const *);
    virtual char const *getMessage();
};

#endif