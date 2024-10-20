#include <stdio.h>

void reverse(char s[], int start, int end) {
    if (start >= end) {
        return;
    }
    char temp = s[start];
    s[start] = s[end];
    s[end] = temp;
    reverse(s, ++start, --end);
}


int itoa(int n, char s[], int i) {
    int x;

    if (n < 0) {
        s[i++] = '-';
        n = -n;
    }
    if ((x = n / 10) > 0) {
        i = itoa(x, s, i);
    }
    s[i++] = n % 10 + '0';

    s[i] = '\0';

    return i;
}

int main() {
    char s[100];
    int n = 10098;
    printf("n = %d\n", n);
    itoa(n, s, 0);
    printf("s = %s\n", s);

    char sp[100] = "hoby";
    printf("\nsp = %s\n", sp);
    reverse(sp, 0, 3);
    printf("sp = %s\n", sp);
    return 0;
}