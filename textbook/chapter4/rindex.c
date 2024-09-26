#include <stdio.h>

int strlen2(char s[]) {
    int c, i = 0;
    do {
        c = s[i++];
    } while (c != '\0');
    return i-1;
}

int rindex2(char s[], char c) {
    for(int i = strlen2(s)-1; i >= 0; --i) {
        if(s[i] == c) {
            return i;
        }
    }
    return -1;
}   


int main() {
    char s1[] = "";
    printf("ri = %d\n", rindex2(s1, 'd'));

    char s2[] = "sdcqq";
    printf("ri = %d\n", rindex2(s2, 'c'));
    
}