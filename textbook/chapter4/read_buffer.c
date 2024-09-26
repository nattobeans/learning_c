#include <stdio.h>
#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch() /* get a (possibly pushed back) character */
{
    if (bufp > 0)
        return buf[--bufp];
    int c = getchar();
    if (c == EOF) {
        bufp = 0;
        buf[bufp] = '\0';
    }
    return c;
}

int ungetch (int c) /* push character back on input */
{
  if (bufp > BUFSIZE)
    printf("ungetch: too many characters\n");
  if (c == EOF) {
    bufp = 0;
    buf[bufp] = '\0';
}
  else
    buf[bufp++] = c;
}

void ungets(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        if (bufp > BUFSIZE) {
            printf("ungetch: too many characters\n");
            break;
        }
        buf[bufp++] = s[i++];
    }
}
  
