#include "DisplayRuan.hpp"
#include "DisplayExceptionRuan.hpp"

#include<stdio.h>

DisplayRuan::DisplayRuan() {}

DisplayRuan::~DisplayRuan() {}

void DisplayRuan::addDigit(Digit digit) {
    switch (digit) {
        case Digit::ZERO:
            printf("▇▇▇▇\n▇  ▇\n▇  ▇\n▇  ▇\n▇▇▇▇\n");
            break;
        case Digit::ONE:
            printf("  ▇ \n ▇▇ \n  ▇ \n  ▇ \n▇▇▇▇\n");
            break;
        case Digit::TWO:
            printf("▇▇▇▇\n   ▇\n▇▇▇▇\n▇   \n▇▇▇▇\n");
            break;
        case Digit::THREE:
            printf("▇▇▇▇\n   ▇\n ▇▇▇\n   ▇\n▇▇▇▇\n");
            break;
        case Digit::FOUR:
            printf("▇▇▇▇\n   ▇\n ▇▇▇\n   ▇\n▇▇▇▇\n");
            break;
        default:
            throw DisplayExceptionRuan("Digit not implemented");
    }
}

void DisplayRuan::clear() {
    printf("\n");
}