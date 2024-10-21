#include "wordlib.h"
#include <stdio.h>



// char char_types[256];

// void initialise_char_types() {
//     int i;
//     for (int i = 'a'; i <= 'z'; i++) {
//         char_types[i] = LETTER;
//     }

//     for (int i = '0'; i <= '9'; i++) {
//         char_types[i] = DIGIT;
//     }
// }


char char_types[256] = {
    ['a' ... 'z'] = LETTER,  // Set 'a' to 'z' as LETTER
    ['0' ... '9'] = DIGIT    // Set '0' to '9' as DIGIT
};

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


// int main() {
//     char s[100];

//     get_word(s, 100);
//     printf("%s\n", s);
// }