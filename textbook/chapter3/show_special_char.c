#include <stdio.h>

void expand(const char s[], char t[]) {
    int i = 0, j = 0;

    while(s[i] != '\0') {
        switch (s[i]) {
            case '\t':
                t[j++] = '\\';
                t[j++] = 't';
                break;
            case '\n':
                t[j++] = '\\';
                t[j++] = 'n';
                break;
            default:
                t[j++] = s[i];
                break;
        } 
        i++;
    }
    t[j] = '\0';
}

int main() {
    char s[] = "jdnj\nwed\tedfqef\0";
    char t[1000];
    printf("%s\n", s);
    printf("%s\n", t);
    expand(s, t);
    printf("%s\n", t);
    
    return 0;
}