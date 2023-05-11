#ifndef CALCULATOR_H
#define CALCULATOR_H

enum Digit { ZERO = 0, ONE = 1, TWO = 2, THREE = 3, FOUR = 4, FIVE = 5, SIX = 6, SEVEN = 7, EIGHT = 8, NINE = 9 };
enum Signal { POSITIVE, NEGATIVE };
enum Operator { SUM, SUBTRACTION, DIVISION, MULTIPLICATION };
enum Control { EQUAL, DECIMAL_SEPARATOR, CLEAR_ERROR, OFF, MEMORY_READ_CLEAR, MEMORY_SUM, MEMORY_SUBTRACTION };

typedef char const* Symbol;

class Key;
class Cpu;
class Keyboard {
   public:
    virtual void receive(Digit) = 0;
    virtual void receive(Operator) = 0;
    virtual void receive(Control) = 0;
    virtual Key* getKey(Digit) = 0;
    virtual Key* getKey(Operator) = 0;
    virtual Key* getKey(Control) = 0;
    virtual Key* getKey(Symbol) = 0;
    virtual void add(Key*) = 0;
    virtual void setCpu(Cpu*) = 0;
};

class Key {
   public:
    virtual void press() = 0;
    virtual Symbol getSymbol() = 0;
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

class Display {
   public:
    virtual void add(Digit) = 0;
    virtual void setSignal(Signal) = 0;
    virtual void addDecimalSeparator() = 0;
    virtual void clear() = 0;
};

class Cpu {
   public:
    virtual void receive(Digit) = 0;
    virtual void receive(Operator) = 0;
    virtual void receive(Control) = 0;
    virtual void setDisplay(Display*) = 0;
};

class Calculator {
  public:
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