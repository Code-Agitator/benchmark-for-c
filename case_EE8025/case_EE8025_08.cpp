//
// Created by develop on 2024/9/25.
//
#include <cstdio>
#include <cstdlib>

#define NULLPTR ((void *)0)
typedef unsigned short int Uint8;

/**
 * 场景：复杂分支
 * 两个相同条件 分别在else中去赋值并且deref
 *
 * 结论：漏洞出现，出现了前后矛盾的条件(前面说param==1 初始化了 NULLPTR 后面又说 param!=1 导致了deref)
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
    Uint8 *p;
    Uint8 param;
    scanf("%d", &param);
    if (param == 1) {
        p = (Uint8 *) NULLPTR;
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