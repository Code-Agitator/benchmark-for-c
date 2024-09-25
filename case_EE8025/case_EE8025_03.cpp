//
// Created by develop on 2024/9/25.
//
#include <cstdio>

#define NULLPTR ((void *)0)
typedef unsigned short int Uint8;

/**
 * 场景：定义一个恒成立的条件去解除空指针
 * 结论：漏洞消失
 */
int main() {
    Uint8 *p = (Uint8 *) NULLPTR;
    Uint8 input;
    scanf("%d", &input);
    if (input >= 0) {
        Uint8 value = 1;
        p = &value;
    }
    printf("%hu\n", *p); // EE0582
    return 0;
}