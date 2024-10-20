#include <stdio.h>

#define strcopy2(S, T) while(*S++ = *T++);

int main() {
    char s[1000];
    char *S = s;
    char t[1000] = "hello world";
    char *T = t;

    strcopy2(S, T);

    printf("String: %s\n", s);

    return 0;
}