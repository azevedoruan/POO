#include "EliasDisplay.hpp"
#include <iostream>

DisplayElias::DisplayElias() {
  Console::init(0,0);
  this->digitsCount = 0;
  this->clear();
}

void DisplayElias::add(Digit digit) {
  
  this->digitsCount++;

  switch (digit) {
  case ZERO:
     Console::setCursor(1, 1+digitsCount * 5);printf("0000");
     Console::setCursor(2, 1+digitsCount * 5);printf("0  0");
     Console::setCursor(3, 1+digitsCount * 5);printf("0  0");
     Console::setCursor(4, 1+digitsCount * 5);printf("0  0");
     Console::setCursor(5, 1+digitsCount * 5);printf("0000");
    break;
  case ONE:
    Console::setCursor(1, 1+digitsCount * 5);printf("1");
    Console::setCursor(2, 1+digitsCount * 5);printf("1");
    Console::setCursor(3, 1+digitsCount * 5);printf("1");
    Console::setCursor(4, 1+digitsCount * 5);printf("1");
    Console::setCursor(5, 1+digitsCount * 5);printf("1");
    break;
  case TWO:
    Console::setCursor(1, 1+digitsCount * 5);printf("2222");
    Console::setCursor(2, 1+digitsCount * 5);printf("   2");
    Console::setCursor(3, 1+digitsCount * 5);printf("2222");
    Console::setCursor(4, 1+digitsCount * 5);printf("2   ");
    Console::setCursor(5, 1+digitsCount * 5);printf("2222");
    break;
  case THREE:
    Console::setCursor(1, 1+digitsCount * 5);printf("3333");
    Console::setCursor(2, 1+digitsCount * 5);printf("   3");
    Console::setCursor(3, 1+digitsCount * 5);printf("3333");
    Console::setCursor(4, 1+digitsCount * 5);printf("   3");
    Console::setCursor(5, 1+digitsCount * 5);printf("3333");
    break;
  case FOUR:
    Console::setCursor(1, 1+digitsCount * 5);printf("4  4");
    Console::setCursor(2, 1+digitsCount * 5);printf("4  4");
    Console::setCursor(3, 1+digitsCount * 5);printf("4444");
    Console::setCursor(4, 1+digitsCount * 5);printf("   4");
    Console::setCursor(5, 1+digitsCount * 5);printf("   4");
    break;
  case FIVE:
    Console::setCursor(1, 1+digitsCount * 5);printf("5555");
    Console::setCursor(2, 1+digitsCount * 5);printf("5   ");
    Console::setCursor(3, 1+digitsCount * 5);printf("5555");
    Console::setCursor(4, 1+digitsCount * 5);printf("   5");
    Console::setCursor(5, 1+digitsCount * 5);printf("5555");
    break;
  case SIX:
    Console::setCursor(1, 1+digitsCount * 5);printf("6666");
    Console::setCursor(2, 1+digitsCount * 5);printf("6   ");
    Console::setCursor(3, 1+digitsCount * 5);printf("6666");
    Console::setCursor(4, 1+digitsCount * 5);printf("6  6");
    Console::setCursor(5, 1+digitsCount * 5);printf("6666");
    break;
  case SEVEN:
    Console::setCursor(1, 1+digitsCount * 5);printf("7777");
    Console::setCursor(2, 1+digitsCount * 5);printf("7  7");
    Console::setCursor(3, 1+digitsCount * 5);printf("7  7");
    Console::setCursor(4, 1+digitsCount * 5);printf("   7");
    Console::setCursor(5, 1+digitsCount * 5);printf("   7");
    break;
  case EIGHT:
    Console::setCursor(1, 1+digitsCount * 5);printf("8888");
    Console::setCursor(2, 1+digitsCount * 5);printf("8  8");
    Console::setCursor(3, 1+digitsCount * 5);printf("8888");
    Console::setCursor(4, 1+digitsCount * 5);printf("8  8");
    Console::setCursor(5, 1+digitsCount * 5);printf("8888");
    break;
  case NINE:
    Console::setCursor(1, 1+digitsCount * 5);printf("9999");
    Console::setCursor(2, 1+digitsCount * 5);printf("9  9");
    Console::setCursor(3, 1+digitsCount * 5);printf("9999");
    Console::setCursor(4, 1+digitsCount * 5);printf("   9");
    Console::setCursor(5, 1+digitsCount * 5);printf("9999");
    break;
  default:
    std::cout << "E!";
    // throw "Digit not implemented!"
  };
};

void DisplayElias::addDecimalSeparator(){
  this->digitsCount++;
  std::cout << " ■ ";
}

void DisplayElias::clear() {
    Console::clearScreen();
    this->digitsCount = 0;
 }

void DisplayElias::setSignal(Signal signal) {
  if (signal == Signal::NEGATIVE) {
    Console::setCursor(1, 0+digitsCount * 5);printf("    ");
    Console::setCursor(2, 0+digitsCount * 5);printf("    ");
    Console::setCursor(3, 0+digitsCount * 5);printf("====");
    Console::setCursor(4, 0+digitsCount * 5);printf("    ");
    Console::setCursor(5, 0+digitsCount * 5);printf("    ");
  }
}