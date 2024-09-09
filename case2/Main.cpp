#include <cstdio>
#include <cstring>

int main(int argc, char* argv[])
{
    printf("hello world");
    return 0;
}

/**
<Fact primary="false" type="Call">Direct : memmove</Fact>
<Fact primary="false" type="TaintFlags">NO_NEW_LINE, NUMBER, STDIN, STRING_LENGTH</Fact>
<Fact primary="true" type="Buffer">[format 0] %d: 2</Fact>
<Fact primary="true" type="Buffer">Buffer Size: 128 bytes</Fact>
<Fact primary="true" type="Buffer">Write Length: 65537 bytes</Fact>
<Fact primary="true" type="Buffer">[var 0] temp: 65519</Fact>
 */
int case2()
{
    int port;
    printf("输入:");
    scanf("%d", &port);
    char str[128] = "";
    char log[500] = "";
    sprintf(str, "%d", port);
    scanf("%499s", &log);
    const size_t len = strlen(str);
    const size_t size = strlen(log);
    memmove(str + len + 16, log, size);
    str[127] = 0;
    return 0;
}
