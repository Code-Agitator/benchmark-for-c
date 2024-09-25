#include <cstring>
#include <cstdio>
#include <cstdarg>
#include <cstdint>
#include <cstdlib>

void case11_1(char *str, char *log, size_t taint);

int main() {
    return 0;
}

const int block_size = 128;
const int OFFSET = 10;

/**
86C7916D-A73B-4EBE-A235-9E570095EE66
<Fact primary="false" type="Call">Direct : memmove</Fact>
<Fact primary="false" type="TaintFlags">NETWORK, NOT_NULL_TERMINATED, XSS</Fact>
 */
int case11(int *input) {
    int taint = (input[0] << 8) | input[2];//  8CB25599-02F1-4525-9DDF-8AE304A01342
    printf("%d", taint);
    char log[500] = "";
    scanf("%499s", &log);
    char *str;
    str = static_cast<char *>(malloc(block_size));
    case11_1(str, log, taint);
    return 0;
}

void case11_1(char *str, char *log, size_t taint) {
    if (taint >= block_size) {
        taint = block_size - 1;
    }
    memmove(str, log, taint);
}



