#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

int myPow(int num, int expon) {
    int res = 1;
    for(int i=0; i < expon; i++) {
        res *= num;
    }
    return res;
}

int htoi(char s[]) {
    int res = 0;
    int j = 0;
    for(int i = strlen(s)-1; i > -1; i--) {
        char c = s[i];
        int x =  myPow(16, j++); 
        if (47 < c && c < 58) {
            res += (c-48) * x;
        } else if (64 < c && c < 71) {
            res += (c-55) * x;
        } else if (96 < c && c < 103) {
            res += (c-87) * x;
        } else {
            printf("invalid hex number %s at character: %c\n", s, c);
            exit(1);
        }
    }
    return res;
}

int main() {
    char s[] = "Ff";
    int i = htoi(s);
    printf("%d\n", i);
}