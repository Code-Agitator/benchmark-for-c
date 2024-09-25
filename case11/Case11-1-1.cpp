#include <cstring>
#include <cstdio>
#include <cstdarg>
#include <cstdint>
#include <cstdlib>

#define block_size 128

void case11_1(char *log, size_t taint);

int main() {
    return 0;
}


/**
漏洞消失
 */
int case11(int *input) {
    int taint = (input[0] << 8) | input[2];//  8CB25599-02F1-4525-9DDF-8AE304A01342
    printf("%d", taint);
    char log[500] = "";
    scanf("%499s", &log);
    case11_1(log, taint);
    return 0;
}

void case11_1(char *log, size_t taint) {
    char *str;
    str = static_cast<char *>(malloc(block_size));
    if (taint >= block_size) {
        taint = block_size - 1;
    }
    memmove(str, log, taint);
}



