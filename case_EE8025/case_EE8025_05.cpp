//
// Created by develop on 2024/9/25.
//
#include <cstdio>

#define NULLPTR ((void *)0)
typedef unsigned short int Uint8;

/**
 * 场景：定义复杂的分支
 * 当input=2的时候给p赋值但是同时设置input=1让后面的p重新置为NULLPTR
 *
 *
 * 结论：漏洞消失了??????
 */
int main() {
    Uint8 *p = (Uint8 *) NULLPTR;
    int input;
    scanf("%d", &input);
    if (input <= 1) {
        Uint8 value = 1;
        p = &value;
    }
    if (input != 1) {
        Uint8 value = 1;
        p = &value;
        input = 1;
    }
    if (input == 1) {
        p = (Uint8 *) NULLPTR;
    }
    printf("%hu\n", *p); // EE0582
    return 0;
}