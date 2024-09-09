#include <cstring>
#include <cstdio>

int case5(int* input)
{
    int taint = (input[0] << 8) | input[2]; //  8CB25599-02F1-4525-9DDF-8AE304A01342
    printf("%d", taint);
    char log[500] = "";
    char str[1000] = "";
    scanf("%499s", &log);
    memmove(str, log, taint);
    return 0;
}

int case5_fix(int* input)
{
    int taint = (input[0] << 8) | input[2]; //  8CB25599-02F1-4525-9DDF-8AE304A01342
    printf("%d", taint);
    char log[500] = "";
    char str[1000] = "";
    scanf("%499s", &log);
    if (taint > 500 || taint < 0)
    {
        taint = 500;
    }
    memmove(str, log, taint);
    return 0;
}
