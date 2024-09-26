#include <stdio.h>
#include <limits.h>

void reverse(char s[]) {
    int start = 0, end = 0;
    while (s[end] != '\0') {
        end++;
    }
    end--;

    while (start < end) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}

void itoa(int n, char s[], int padding) {
    int i = 0, sign = 1;
    unsigned int num;
    if (n < 0) {
        num = (unsigned int)(n);  
        sign = -1;  
    } else { 
        num = n; 
    }

    do {    
        s[i++] = num % 10 + '0';  
        padding--; 
    } while ((num /= 10) > 0); 

    while(padding-- > 0) {
        s[i++] = '0';
    }

    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

int main() {

    printf("Start: %d\n", 30);
    char s[100];
    itoa(30, s, 6);
    printf("TO STRING: %s\n", s);
}
    return 0;