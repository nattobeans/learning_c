#include <stdio.h>
// #include <conio.h>

int get_double(double *pn) /* get next integer from input */
{
    int c, sign;

    while ((c = getchar()) == ' ' || c == '\n' || c == '\t')
    ;   /* skip white space */
    sign = 1;
    if (c == '+' || c == '-') { /* record sign */
        sign = (c=='+') ? 1 : -1;
        c = getchar();
    }
    for (*pn = 0; c >= '0' && c <= '9'; c = getchar())
        *pn = 10 * *pn + c - '0';

    if (c == '.') {
        c = getchar();
        double track = 0.1;
        for (; c >= '0' && c <= '9'; c = getchar()) {
            *pn += (c - '0') * track;
            track *= 0.1;        
        }
    }
    *pn *= sign;
    return(c);
}

int main () {
    int exit = 0;
    while (exit != 'X') {
        double d = 0.0;
        double *pd = &d;
        exit = get_double(pd);
        printf("double is %f\n", *pd);
        printf("exit is %d\n", exit);
    }
    
}