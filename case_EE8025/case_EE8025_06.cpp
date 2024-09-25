//
// Created by develop on 2024/9/25.
//
#include <cstdio>
#include <cstdlib>

#define NULLPTR ((void *)0)
typedef unsigned short int Uint8;

/**
 * 场景：定义复杂的分支
 * 连续判断两次 同一条件：
 * 1. 第一次成立后 修复空指针
 * 2. 第二次成立后 进行解引用
 *
 * 结论：漏洞存在，误报
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
    }
    if (1 == param) {
        printf("%hu\n", *p); // EE0582
    }

    return 0;
}