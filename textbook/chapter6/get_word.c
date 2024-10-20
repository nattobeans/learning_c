#include <stdio.h>

#define LETTER 'a'
#define DIGIT  '0'


char char_types[256];

void initialise_char_types() {
    int i;
    for (int i = 'a'; i <= 'z'; i++) {
        char_types[i] = LETTER;
    }

    for (int i = '0'; i <= '9'; i++) {
        char_types[i] = DIGIT;
    }
}


int get_word(char *w, int lim) 
{
    int c, t;
    if (char_types[c = *w++ = getchar()] != LETTER) {
        *w = '\0';
        return(c);

    }

    while (--lim > 0) {
        t = char_types[c = *w++ = getchar()];
        if (t != LETTER && t != DIGIT) {
            break;
        }
    }
    *(w-1) = '\0';
    return (LETTER);
}


int main() {
    char s[100];
    initialise_char_types();

    get_word(s, 100);
    printf("%s\n", s);
}