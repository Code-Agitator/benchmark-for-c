/**
 * 修复完成
 */
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

void pl_trace(int valnum, ...);

int main() {
    return 0;
}

/**
<Fact primary="false" type="Call">Direct : memmove</Fact>
<Fact primary="false" type="TaintFlags">NETWORK, NOT_NULL_TERMINATED, NUMBER</Fact>
<Fact primary="true" type="Buffer">Buffer Size: 64 bytes</Fact>
<Fact primary="true" type="Buffer">Write Length: 27656194 bytes</Fact>
<Fact primary="true" type="Buffer">[var 0] in_msglen: 27656168</Fact>
 */
void somewhere(const int *input) {
    int in_msglen = (input[0] << 8) | input[2];//  8CB25599-02F1-4525-9DDF-8AE304A01342  0
    // 无法消除 ============
//    if (in_msglen + TRACE_DATA_OFFSET + 16 >= TINY_BUFFER_SIZE || in_msglen < 0) {
//        in_msglen = 10;
//        return;
//    }
    // ===================
    pl_trace(TRACE_TYPE_HEX, in_msglen); // 1
}

int check_in_msglen(int *in_msglen) {
    if (*in_msglen + TRACE_DATA_OFFSET + 16 >= TINY_BUFFER_SIZE || *in_msglen < 0) {
        *in_msglen = 0;
        return -1;
    }
    return 1;
}

void pl_trace(int valnum, ...) {
    va_list args;
    va_start(args, valnum);
    int in_msglen = va_arg(args, int); // 2
    va_end(args);
    // 可以消除  =========================

    int result = check_in_msglen(&in_msglen);
    if (result == -1) {
        return;
    }
    // ===================
    int LOG_BUF_SIZE = BIG_BUFFER_SIZE;
    uint8_t memp_type = TYPE_BIG;
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
    memmove(str + TRACE_DATA_OFFSET + 16, log, in_msglen); // *
}