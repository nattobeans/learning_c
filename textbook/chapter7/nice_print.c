#include <stdio.h>

int check_printable(char c) {
    return '0' <= c && '9' >= c || 'A' <= c && 'Z' >= c|| 'a' <= c && 'z' >= c;
}

int main() {
    char c;
    int i;

    i = 0;
    flockfile(stdin);
    while ((c = getchar_unlocked()) != EOF){
        i++;
        if (check_printable(c)) {
            putchar(c);
        } else {
            printf("0x%x", c);
        }
        if (40 < i && ' ' == c || 50 < i) {
            putchar('\n');
            i = 0;
        }
    } 
    funlockfile(stdin);
    return 0;
}