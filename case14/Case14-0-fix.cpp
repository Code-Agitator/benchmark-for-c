//
// Created by develop on 2024/9/11.
//
#include <cstdint>
#include "cstdarg"
#include "cstdlib"
#include "cstdio"
#include <cstring>

#define TYPE_BIG 1
#define TYPE_TINY 2
#define BIG_BUFFER_SIZE 128
#define TINY_BUFFER_SIZE 64
#define TRACE_DATA_OFFSET 10

#define TRACE_TYPE_HEX 1
#define TRACE_TYPE_OTHER 2

void pl_trace(uint8_t valnum, ...);

int main() {
    return 0;
}

void somewhere(const int *input) {
    int in_msglen = (input[0] << 8) | input[2];//  8CB25599-02F1-4525-9DDF-8AE304A01342  0
    uint8_t trace_type = TRACE_TYPE_HEX;
    if (in_msglen % 2 == 0) {
        trace_type = TRACE_TYPE_HEX;
    } else {
        trace_type = TRACE_TYPE_OTHER;
    }
    pl_trace(trace_type, in_msglen); // 1
}

void pl_trace(uint8_t valnum, ...) {
    va_list args;
    va_start(args, valnum);
    int in_msglen = va_arg(args, int); // 2
    va_end(args);
    int LOG_BUF_SIZE = BIG_BUFFER_SIZE;
    uint8_t memp_type = BIG_BUFFER_SIZE;
    if (valnum == TRACE_TYPE_HEX) {
        memp_type = TYPE_BIG;
        LOG_BUF_SIZE = BIG_BUFFER_SIZE;
    } else {
        memp_type = TYPE_TINY;
        LOG_BUF_SIZE = TINY_BUFFER_SIZE;
    }
    char *str;
    if (memp_type == TYPE_BIG) {
        str = static_cast<char *>(malloc(BIG_BUFFER_SIZE));
    } else {
        str = static_cast<char *>(malloc(TINY_BUFFER_SIZE)); // 3
    }
    char log[500] = "";
    scanf("%499s", *log);
    if (in_msglen + TRACE_DATA_OFFSET + 16 >= LOG_BUF_SIZE) {
        in_msglen = LOG_BUF_SIZE - TRACE_DATA_OFFSET - 16 - 1;
    }
    memmove(str + TRACE_DATA_OFFSET + 16, log, in_msglen); // *
}