//
// Created by develop on 2024/9/25.
//
#include <cstdio>

#define NULLPTR ((void *)0)
#define TRUE true
typedef unsigned short int Uint8;

extern Uint8 test_flag;
/**
 * cm_iot 在这里做了异常上报但是没有实际关闭应用 不确定是什么
 */
#define OSA_ASSERT(expr) {\
    if (!(expr)) {        \
        if(TRUE != test_flag)  { \
                              \
        }\
    }\
}

/**
 * 待完善
 * 场景：模拟CM_IOT场景
 * 结论：
 */
int main() {
    Uint8 *p = (Uint8 *) NULLPTR;
    Uint8 input;
    scanf("%d", &input);
    if (input % 2 == 0) {
        Uint8 value = 1;
        p = &value;
    }
    OSA_ASSERT(NULLPTR != p)
    printf("%hu\n", *p); // EE0582
    return 0;
}