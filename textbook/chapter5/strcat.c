#include <stdio.h>

void strcat2(char *s, char *t) {
    while(*s++) {};
    s--;
    while(*t) {
        *s++ = *t++;
    }
    *s = '\0';
}

int main() {
    char s[100] = "hello";
    char t[100] = " world";

    strcat2(s, t);
    printf("String: %s\n", s);

    return 0;
}