#include <stdio.h>

char lower(int c) {
    return 64 < c && c < 71 ? c + 32: c; 
}

int main() {
    printf("%c\n", lower('A'));
    printf("%c\n", lower('a'));
    printf("%c\n", lower('\n'));
}