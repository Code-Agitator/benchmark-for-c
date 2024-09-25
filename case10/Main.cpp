#include <cstring>
#include <cstdio>
#include <cstdarg>
#include <cstdint>
#include <cstdlib>

void case10_1(char *log...);

int main() {
    return 0;
}

const int block_size = 128;
const int OFFSET = 10;

/**
86C7916D-A73B-4EBE-A235-9E570095EE66
<Fact primary="false" type="Call">Direct : memmove</Fact>
<Fact primary="false" type="TaintFlags">NETWORK, NOT_NULL_TERMINATED, XSS</Fact>
<Fact primary="true" type="Buffer">Buffer Size: 128 bytes</Fact>
<Fact primary="true" type="Buffer">Write Length: -9160858482657329262 bytes</Fact>
<Fact primary="true" type="Buffer">[var 0] str.$offset: 0</Fact>
<Fact primary="true" type="Buffer">[var 1] taint: 9285885591052222354</Fact>
 */
int case10(int *input) {
    int taint = (input[0] << 8) | input[2];//  8CB25599-02F1-4525-9DDF-8AE304A01342
    printf("%d", taint);
    char log[500] = "";
    scanf("%499s", &log);
    case10_1(log, taint);
    return 0;
}

void case10_1(char *log...) {
    char *str;
    str = static_cast<char *>(malloc(block_size));
    va_list args;
    va_start(args, log);
    uint32_t taint = va_arg(args, uint32_t);
    va_end(args);
    if (taint + 16 >= block_size) {
        taint = block_size - 16 - 1;
    }
    memmove(str + 16, log, taint);
}



