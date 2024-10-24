#include "custom_file.h"
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        return -1;
    }

    FILEJ *fp;

    fp = fopenj(argv[1], "r");
    if (fp == NULL) {
        write(2, "miss mode \n", 14);
        return 1;
    }
        
    char stest[13] = "STARTED WORK\n";
    write(1, stest, sizeof(stest));

    char s[3] = " \n";
    char c = _fillbuf(fp);
    s[0] = c;
    char stest1[16] = "STARTED WORK 2\n";
    write(1, stest1, sizeof(stest1));
    write(1, s, sizeof(s));
    while (c != EOF) {
        s[0] = c;
        write(1, s, sizeof(s));
        c = _fillbuf(fp);
    }
    return 0;
}