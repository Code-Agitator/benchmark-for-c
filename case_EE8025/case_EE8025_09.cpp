//
// Created by develop on 2024/9/25.
//
#include <cstdio>
#include <cstdlib>

#define NULLPTR ((void *)0)
typedef unsigned short int Uint8;

/**
 * 待完善
 * 场景：复杂分支
 * 两个相同条件 不在if中明确设置null
 *
 * 结论：漏洞存在
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
    if (param == 1) {
        // do nothing
    } else {
        fill_value(&p);
    }
    if (param == 1) {
        // do nothing
    } else {
        printf("%d", *p);
    }
    return 0;
}