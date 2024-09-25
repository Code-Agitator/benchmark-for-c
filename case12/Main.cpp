#include <cstring>
#include <cstdio>
#include <cstdarg>
#include <cstdint>
#include <cstdlib>


int main() {
    return 0;
}

const int block_size = 128;

int case12(int *input) {
    int taint = (input[0] << 8) | input[2];//  8CB25599-02F1-4525-9DDF-8AE304A01342
    char log[500] = "";
    char str[block_size] = "";
    scanf("%499s", &log);
    if (taint >= block_size) {
        taint = 1;
    }
    memmove(str, log, taint);
    return 0;
}




