#include <stdio.h>

int main() {
    int i, lim = 100;
    char c;
    char s[lim];

    for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i) {
        s[i] = c;
    }
    s[i] = '\0';
    printf("You entered: %s\n", s);
    printf("\n");

    char d;
    char t[lim];
    int j;
    for(j=0; j < lim - 1; j++) {
        if ((d = getchar()) == '\n' || d == EOF) {
            break;
        } 
        t[j] = d;
    }
    t[j] = '\0';
    printf("You entered: %s\n", t);

    return 0;
}

