#include <stdio.h>
#include <stdlib.h>


#define LIM 100
int numstack[LIM];
int idx = -1;

int pop() {
    return idx > -1 ? numstack[idx--] : 0;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("please supply commands\n");
        return 1;
    }

    int x, res;
    char *s, op;

    res = atoi(*++argv);
    argc -= 1;
    while (--argc > 0) {
        s = *++argv;
        if ('0' <= s[0] && '9' >= s[0]) {
            numstack[++idx] = atoi(s);
            continue;
        }
        op = s[0];
        x = pop();
        if (x == 0)
            break;
        if (op == '+') {
            res += x;
        } else if (op == '-') {
            res -= x;
        } else if (op == '*' || op == 'a') {
            res *= x;

        } 
        else {
            printf("put in the correct char u nce\n");
            break;
        }
    } 
    printf("%d\n", res);
    return 0;
}