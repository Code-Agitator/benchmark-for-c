//
// Created by develop on 2024/9/25.
//
#include "stdio.h"

#define NULLPTR ((void *)0)
typedef unsigned short int Uint8;

/**
 * 直接解引用一个空指针
 */
int main() {
    Uint8 *p = (Uint8 *) NULLPTR;
    printf("%hu\n", *p); // EE0582
    return 0;
}