//
// Created by develop on 2024/9/25.
//
#include <cstdio>
#include <cstdlib>

#define NULLPTR ((void *)0)
typedef unsigned short int Uint8;

/**
 * 场景：定义复杂的分支
 * 连续在一个条件中：
 * 1. 修复空指针
 * 2. 进行解引用
 *
 * 结论：漏洞消失
 */
void fill_value(Uint8 **p) {
    size_t size = sizeof(Uint8);
    *p = (Uint8 *) malloc(size);
    if (*p == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1); // 如果内存分配失败，则退出程序
    }
    **p = 1;
}

int main() {
    Uint8 *p = (Uint8 *) NULLPTR;
    Uint8 param;
    scanf("%d", &param);
    if (param > 1) {
        return 1;
    }
    if (1 == param) {
        fill_value(&p);
        printf("%hu\n", *p); // EE0582
    }
    return 0;
}