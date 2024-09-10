#include <cstring>
#include <cstdio>
#include <cstdarg>
#include <cstdint>

void case6_1(char *str, bool flag, char *log...);

int main() {
    return 0;
}

const int block_size = 128;
const int OFFSET = 10;

int case6(int *input) {
    int taint = (input[0] << 8) | input[2];//  8CB25599-02F1-4525-9DDF-8AE304A01342
    printf("%d", taint);
    char log[500] = "";
    scanf("%499s", &log);
    char *str;
    bool flag = strlen(log) % 2 == 0;
    if (flag) {
        str = new char[block_size];
    } else {
        str = new char[64];
    }
    case6_1(str, flag, log, taint);
    return 0;
}

void case6_1(char *str, bool flag, char *log...) {
    if (flag) {
        va_list args;
        va_start(args, log);
        uint32_t taint = va_arg(args, uint32_t);
        va_end(args);
        if ((taint + OFFSET + 16) >= block_size) {
            taint = block_size - OFFSET - 16 - 1;
        }
        memmove(str, log, taint);
    }

}



