#include <stdio.h>

int c = -1;

int getch() /* get a (possibly pushed back) character */
{
    int x;
    if (c > 0) {
        x = c;
        c = -1;
        return x;
    } else   
        return getchar();
}

int ungetch (char new_c) /* push character back on input */
{
    if (c > -1) {
        printf("ungetch: buffer char already exists.");
    } else {
        c = new_c;
    }
}
