#ifndef CPU_H
#define CPU_H

#include "Calculator.hpp"

class CpuRuan : public Cpu {
private:
public:
    void receive(Digit);
    void receive(Operator);
    void receive(Control);
    void setDisplay(Display*);
};

#endif