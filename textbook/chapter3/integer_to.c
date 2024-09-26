#include <stdio.h>
#include <limits.h>

void itob(int n, char s[]) {
    int j = 0;
    printf("n=%d\n", n);
    for(int i = 31; i >=0; i--) {
        unsigned mask = 1 << i;
        unsigned bit = (mask & n) ? 1 : 0;
        s[j++] = bit + '0';
    }
    s[j] = '\0';
}

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

void itoh(int n, char s[]) {
    int i = 0, sign = 0;
    unsigned int num = (unsigned int) n;

    if (n < 0) {
        sign = 1;
    }

    do {
        int h = num % 16;
        if (h < 10) {
            s[i++] = h + '0';
        } else {
            s[i++] = h - 10 + 'a';
        }
    } while((num /= 16) > 0);
    if (sign) {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}


int main() {
    printf("Start ITOA: %d\n", INT_MIN);
    char s1[100];
    itob(INT_MIN, s1);
    printf("TO STRING: %s\n\n", s1);

    printf("Start ITOB: %d\n", INT_MIN);
    char s2[40];
    itoh(INT_MIN, s2);
    printf("TO STRING: %s\n\n", s2);
    return 0;
}