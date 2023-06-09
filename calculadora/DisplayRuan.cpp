#include "DisplayRuan.hpp"

DisplayRuan::DisplayRuan() {
    clear();
}

DisplayRuan::~DisplayRuan() {}

void DisplayRuan::add(Digit digit) {
    if (currentPos >= MAX_CHARACTERS)
        return;
        
    digits[currentPos] = digit;

    for (int i = 0; i <= currentPos; i++) {
        int pos = (MAX_CHARACTERS - 1) - currentPos + i;
        switch (digits[i]) {
            case Digit::ZERO:
                printDigit(pos, "▇▇▇▇", "▇  ▇", "▇  ▇", "▇  ▇", "▇▇▇▇");
                break;
            case Digit::ONE:
                printDigit(pos, "  ▇ ", " ▇▇ ", "  ▇ ", "  ▇ ", "▇▇▇▇");
                break;
            case Digit::TWO:
                printDigit(pos, "▇▇▇▇", "   ▇", "▇▇▇▇", "▇   ", "▇▇▇▇");
                break;
            case Digit::THREE:
                printDigit(pos, "▇▇▇▇", "   ▇", " ▇▇▇", "   ▇", "▇▇▇▇");
                break;
            case Digit::FOUR:
                printDigit(pos, "▇  ▇", "▇  ▇", "▇▇▇▇", "   ▇", "   ▇");
                break;
            case Digit::FIVE:
                printDigit(pos, "▇▇▇▇", "▇   ", "▇▇▇▇", "   ▇", "▇▇▇▇");
                break;
            case Digit::SIX:
                printDigit(pos, "▇▇▇▇", "▇   ", "▇▇▇▇", "▇  ▇", "▇▇▇▇");
                break;
            case Digit::SEVEN:
                printDigit(pos, "▇▇▇▇", "   ▇", "   ▇", "   ▇", "   ▇");
                break;
            case Digit::EIGHT:
                printDigit(pos, "▇▇▇▇", "▇  ▇", "▇▇▇▇", "▇  ▇", "▇▇▇▇");
                break;
            case Digit::NINE:
                printDigit(pos, "▇▇▇▇", "▇  ▇", "▇▇▇▇", "   ▇", "▇▇▇▇");
                break;
            default:
                throw CalculatorError("Digit not implemented");
        }
    }
    currentPos++;
}

void DisplayRuan::setSignal(Signal signal) {
    Console::setCursor(3, 1);
    if (signal == Signal::NEGATIVE)
        printf("▇▇▇");
    else
        printf("   ");
}

void DisplayRuan::addDecimalSeparator() {
    throw CalculatorError("Decimal separator not implemented in DisplayRuan");
}

void DisplayRuan::clear() {
    Console::clearScreen();
    currentPos = 0;
    for (int i = 0; i < MAX_CHARACTERS; i++) {
        digits[i] = Digit::ZERO;
    }
    printDigit(7, "▇▇▇▇", "▇  ▇", "▇  ▇", "▇  ▇", "▇▇▇▇");
    Console::setCursor(7, 1);
}

void DisplayRuan::printDigit(int index, char const* row1, char const* row2, char const* row3, char const* row4, char const* row5) {
    Console::setCursor(1, (index * 6) + 6);
    printf("%s", row1);
    Console::setCursor(2, (index * 6) + 6);
    printf("%s", row2);
    Console::setCursor(3, (index * 6) + 6);
    printf("%s", row3);
    Console::setCursor(4, (index * 6) + 6);
    printf("%s", row4);
    Console::setCursor(5, (index * 6) + 6);
    printf("%s", row5);
    Console::setCursor(7, 1);
}