//
// Created by develop on 2024/9/10.
//
#include <cstring>
#include <cstdio>
#include <cstdlib>


int main() {
    return 0;
}

const int block_size = 128;

/**
<Fact primary="false" type="Call">Direct : memmove</Fact>
<Fact primary="false" type="TaintFlags">NO_NEW_LINE, NUMBER, STDIN, STRING_LENGTH</Fact>
<Fact primary="true" type="Buffer">Buffer Size: 128 bytes</Fact>
<Fact primary="true" type="Buffer">Write Length: 262143 bytes</Fact>
<Fact primary="true" type="Buffer">[var 0] taint: 262143</Fact>
 */
int case7(int *input) {
    char log[500] = "";
    char str[block_size] = "";
    scanf("%499s", &log);
    const size_t taint = strlen(log);
    memmove(str, log, taint);
    return 0;
}

int case7_1_(char *str, char *log, size_t taint) {
    memmove(str, log, taint);
    return 1;
}
/**
<Fact primary="false" type="Call">Direct : memmove</Fact>
<Fact primary="false" type="TaintFlags">NO_NEW_LINE, NUMBER, STDIN, STRING_LENGTH</Fact>
<Fact primary="true" type="Buffer">Buffer Size: 128 bytes</Fact>
<Fact primary="true" type="Buffer">Write Length: 3661001319180402686 bytes</Fact>
<Fact primary="true" type="Buffer">[var 0] str.$offset: 0</Fact>
<Fact primary="true" type="Buffer">[var 1] taint: 3661001319180402686</Fact>
 */
int case7_1(int *input) {
    char log[500] = "";
    char str[block_size] = "";
    scanf("%499s", &log);
    const size_t taint = strlen(log);
    case7_1_(str, log, taint);
    return 0;
}







