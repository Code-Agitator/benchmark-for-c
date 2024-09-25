//
// Created by develop on 2024/9/11.
//
//
// Created by develop on 2024/9/10.
//
#include <cstring>
#include <cstdio>
#include <cstdarg>
#include <cstdlib>
#include <cstdint>


int main() {
    return 0;
}

const int block_size = 128;


int case9(int *input) {
    int taint = (input[0] << 8) | input[2];//  8CB25599-02F1-4525-9DDF-8AE304A01342
    char log[500] = "";
    char *str;
    scanf("%499s", &log);
    str = (char *) (malloc(block_size));
    if (taint >= block_size) {
        taint = block_size - 1;
    }
    if (taint < 0) {
        taint = 0;
    }
    memmove(str, log, taint);
    return 0;
}











