#include <stdio.h> 
#include <string.h>


int any(char s[], char c) {
    for(int i = 0; i < strlen(s); i++ ) {
        if (s[i] == c) {
            return i;
        }
    }

    return -1;
}


int main() {

    char s[] = "dnjkejnfnafqiflieifqezniocf";
    char c = 'z';

    printf("index = %d\n", any(s, c));


    return 0;
}