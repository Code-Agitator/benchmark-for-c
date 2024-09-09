#include <cstdio>
#include <cstring>

int main(int argc, char* argv[])
{
    printf("hello world");
    return 0;
}


/**
 *  <Fact primary="false" type="Call">Direct : memmove</Fact>
    <Fact primary="false" type="TaintFlags">NO_NEW_LINE, NUMBER, STDIN, STRING_LENGTH</Fact>
    <Fact primary="true" type="Buffer">[format 0] %d: 9</Fact>
    <Fact primary="true" type="Buffer">Buffer Size: 128 bytes</Fact>
    <Fact primary="true" type="Buffer">Write Length: 344 bytes</Fact>
    <Fact primary="true" type="Buffer">[var 0] size: 319</Fact>
 */
void case1()
{
    int port;
    printf("输入:");
    scanf("%d", &port);

    char str[128] = "";
    char log[500] = "";
    sprintf(str, "%d", port);
    const size_t len = strlen(str);
    scanf("%499s", &log);
    log[499] = 0;
    const size_t size = strlen(log);
    const size_t temp = size;
    memmove(str + len + 16, log, temp);
}


void case1_fix()
{
    int port;
    printf("输入:");
    scanf("%d", &port);

    char str[128] = "";
    char log[500] = "";
    sprintf(str, "%d", port);
    scanf("%499s", &log);
    log[499] = 0;
    const size_t len = strlen(str);
    const size_t size = strlen(log);
    size_t temp = size + len + 16;
    if (temp > 127)
    {
        temp = 128 - len - 16;
    }
    else
    {
        temp = size;
    }
    memmove(str + len + 16, log, temp);
    str[127] = 0;
}
