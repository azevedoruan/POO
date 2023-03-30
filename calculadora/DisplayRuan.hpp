#include "Calculator.hpp"

class DisplayRuan : public Display {
public:
    DisplayRuan();
    ~DisplayRuan();
    void addDigit(Digit);
    void clear();
};