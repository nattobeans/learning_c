#include <stdio.h>

int string_len(char s[]) {
    int k=0;
    while (s[k] != '\0') { 
        k++;
    }
    return k;
}

int check_is_letter(const char c) {
    return (c >= 'a' && c <= 'z') ? 1 : 0;
}

int check_valid_span(char s[], int i, int n) {
    return (i > 0 && check_is_letter(s[i-1]) && i+1 < n && check_is_letter(s[i+1])) ? 1 : 0;
}

int add_span(char t[], int j, const char start, const char end) {
    for(int i = start+1; i < end; i++) {
        t[j++] = i;
    }
    return j;
}
 
void expand(char s[], char t[]) {
    int i=0, j=0;
    int n=string_len(s);
    
    while (s[i] != '\0') {
        for (;i<n && s[i] != '-'; ++i) {
            t[j++] = s[i];
        }

        if (check_valid_span(s, i, n)) {
            j = add_span(t, j, s[i-1], s[i+1]);
        }
        i++;
    }
    t[j] = '\0';
}

int main() {
    char s[] = "ndsa-z   a-b-f\0";
    char t[1000];
    printf("%s\n", s);
    printf("%s\n", t);
    expand(s, t);
    printf("%s\n", t);
}