#include <string.h>
#include <stdio.h>

#include "Calculator.hpp"
#include "DisplayRuan.hpp"
#include "CpuRuan.hpp"
#include "KeyboardRuan.hpp"
#include "KeyRuan.hpp"
#include "CalculatorRuan.hpp"

void calculatorTest() {
    CpuRuan cpu;
    DisplayRuan display;
    KeyboardRuan keyboard;
    KeyDigitRuan key0("0", Digit::ZERO);
    KeyDigitRuan key1("1", Digit::ONE);
    KeyDigitRuan key2("2", Digit::TWO);
    KeyDigitRuan key3("3", Digit::THREE);
    KeyDigitRuan key4("4", Digit::FOUR);
    KeyDigitRuan key5("5", Digit::FIVE);
    KeyDigitRuan key6("6", Digit::SIX);
    KeyDigitRuan key7("7", Digit::SEVEN);
    KeyDigitRuan key8("8", Digit::EIGTH);
    KeyDigitRuan key9("9", Digit::NINE);
    KeyOperatorRuan keySum("+", Operator::SUM);
    KeyOperatorRuan keySub("-", Operator::SUBTRACTION);
    KeyOperatorRuan keyMul("*", Operator::MULTIPLICATION);
    KeyOperatorRuan keyDiv("/", Operator::DIVISION);
    KeyControlRuan keyEqual("=", Control::EQUAL);
    KeyControlRuan keyClearError("ce", Control::CLEAR_ERROR);
    CalculatorRuan calculator;

    cpu.setDisplay(&display);
    keyboard.setCpu(&cpu);
    keyboard.add(&key0);
    keyboard.add(&key1);
    keyboard.add(&key2);
    keyboard.add(&key3);
    keyboard.add(&key4);
    keyboard.add(&key5);
    keyboard.add(&key6);
    keyboard.add(&key7);
    keyboard.add(&key8);
    keyboard.add(&key9);
    keyboard.add(&keySum);
    keyboard.add(&keySub);
    keyboard.add(&keyMul);
    keyboard.add(&keyDiv);
    keyboard.add(&keyEqual);
    keyboard.add(&keyClearError);
    calculator.setCpu(&cpu);
    calculator.setDisplay(&display);
    calculator.setKeyboard(&keyboard);

    calculator.getKeyboard()->getKey("-")->press();
    calculator.getKeyboard()->getKey("2")->press();
    calculator.getKeyboard()->getKey("*")->press();
    calculator.getKeyboard()->getKey("3")->press();
    calculator.getKeyboard()->getKey("+")->press();
    calculator.getKeyboard()->getKey("6")->press();
    calculator.getKeyboard()->getKey("=")->press();
}

int main() {
    try {
        calculatorTest();
    } catch (CalculatorError e) {
        char string[50] = "Error: ";
        strcat(string, e.getMessage());
        printf("%s\n", string);
    }

    return 0;
}