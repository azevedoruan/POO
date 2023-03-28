/* PRIMEIRA ABSTRAÇÃO DE UMA CALCULADORA */

class Button {
public:
    Button();
    ~Button();
    void press(const char);
};

class Keyboard {
private:
    Button** buttons;
public:
    Keyboard();
    ~Keyboard();
    Button** getButtons();
    Button* findButton(const char);
    void send();
};

class Cpu {
public:
    Cpu();
    ~Cpu();
};

class Display {
public:
    Display();
    ~Display();
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