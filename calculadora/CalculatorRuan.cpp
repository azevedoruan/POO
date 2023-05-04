#include "CalculatorRuan.hpp"

void CalculatorRuan::setDisplay(Display *display) {
    this->display = display;
}

Display *CalculatorRuan::getDisplay() {
    return display;
}

void CalculatorRuan::setCpu(Cpu *cpu) {
    this->cpu = cpu;
}

Cpu *CalculatorRuan::getCpu() {
    return cpu;
}

void CalculatorRuan::setKeyboard(Keyboard *keyboard) {
    this->keyboard = keyboard;
}

Keyboard *CalculatorRuan::getKeyboard() {
    return keyboard;
}