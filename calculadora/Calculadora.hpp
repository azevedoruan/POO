/* PRIMEIRA ABSTRAÇÃO DE UMA CALCULADORA */

class Button {
public:
    virtual void press(const char) = 0;
};

class Keyboard {
private:
    Button* buttons;
public:

};

class Cpu {

};

class Display {
public:
    void show();
};

class Calculator {
private:
    Display* display;
    Cpu* cpu;
    Keyboard* keyboard;
public:
    Calculator(Display*, Cpu*, Keyboard*);
    ~Calculator();
};