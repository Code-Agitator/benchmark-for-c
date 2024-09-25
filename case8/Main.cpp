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

/**
4E6C9F14-EC4D-099A-159A-0A9400BC6CE9
<Fact primary="false" type="Call">Direct : memmove</Fact>
<Fact primary="false" type="TaintFlags">NETWORK, NOT_NULL_TERMINATED, XSS</Fact>
<Fact primary="true" type="Buffer">Buffer Size: 128 bytes</Fact>
<Fact primary="true" type="Buffer">Write Length: (very large value) bytes</Fact>
 */
int case8(int *input) {
    int taint = (input[0] << 8) | input[2];//  8CB25599-02F1-4525-9DDF-8AE304A01342
    char log[500] = "";
    char *str;
    scanf("%499s", &log);
    bool flag = strlen(log) % 2 == 0;
    if (flag) {
        str = static_cast<char *>(malloc(block_size));
    } else {
        str = static_cast<char *>(malloc(64));
    }
    if (flag) {
        memmove(str, log, taint);
    }
    return 0;
}


int case8_fix(int *input) {
    int taint = (input[0] << 8) | input[2];//  8CB25599-02F1-4525-9DDF-8AE304A01342
    char log[500] = "";
    char *str;
    scanf("%499s", &log);
    bool flag = strlen(log) % 2 == 0;
    if (flag) {
        str = static_cast<char *>(malloc(block_size));
    } else {
        str = static_cast<char *>(malloc(64));
    }
    if (flag) {
        if (taint >= block_size) {
            taint = block_size - 1;
        }
        if (taint < 0) {
            taint = 0;
        }
        memmove(str, log, taint);
    }
    return 0;
}











