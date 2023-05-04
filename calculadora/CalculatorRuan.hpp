#ifndef CALCULATOR_MAIN_H
#define CALCULATOR_MAIN_H

#include "Calculator.hpp"

class CalculatorRuan : public Calculator {
  Display *display;
  Cpu *cpu;
  Keyboard *keyboard;
public:
  void setDisplay(Display *);
  Display *getDisplay();
  void setCpu(Cpu *);
  Cpu *getCpu();
  void setKeyboard(Keyboard *);
  Keyboard *getKeyboard();
};

#endif