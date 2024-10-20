#include <stdio.h>

int main(int argc, char *argv[]) {
    // int i;
    // for (i=1; i<argc; ++i) {
    //     printf("%s%c", argv[i], i < (argc-1) ? ' '  : '\n');
    // }

    while(--argc > 0) {
        printf("%s%c", *++argv, (argc > 1) ? ' ' : '\n');
    }
    return 0;
}