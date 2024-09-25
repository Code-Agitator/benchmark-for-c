#include "iostream"
#include "stdint.h"
#include <typeinfo>

int main() {
    uint8_t a = 1;
    uint8_t b = 2;
    uint8_t result = (a + b + 1) / -2;
    std::cout << "type:" << typeid((a + b + 1) / 2).name() << std::endl;
    std::cout << "result:" << static_cast<int>(result);

}