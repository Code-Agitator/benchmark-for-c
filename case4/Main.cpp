//
// Created by 14820 on 2024/9/10.
//
#include <cstdio>
#include <cstring>

int main(int argc, char* argv[])
{
    return 0;
}

#include <cstring>
#include <cstdio>

size_t transform(size_t len);
/**
<Fact primary="false" type="Call">Direct : memmove</Fact>
<Fact primary="false" type="TaintFlags">NO_NEW_LINE, NUMBER, STDIN, STRING_LENGTH</Fact>
<Fact primary="true" type="Buffer">[format 0] %d: 2</Fact>
<Fact primary="true" type="Buffer">Buffer Size: 128 bytes</Fact>
<Fact primary="true" type="Buffer">Write Length: 5785947646704812032 bytes</Fact>
<Fact primary="true" type="Buffer">[var 0] temp: 5785947646704812014</Fact>
 */
int case4()
{
    int port;
    printf("输入:");
    scanf("%d", &port);

    char str[128] = "";
    char log[500] = "";
    sprintf(str, "%d", port);
    scanf("%s", &log);
    const size_t len = strlen(str);
    const size_t temp = transform(strlen(log));
    memmove(str + len + 16, log, temp);
    str[127] = 0;
    return 0;
}


size_t transform(size_t len)
{
    return len / 10;
}
