#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>  

#define BUFFSIZE 512

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Supply at least one filename: `%s <file 1> <file2> ...`", argv[1]);
        return -1;
    }

    int fd, n;
    char buff[BUFFSIZE];

    if ((fd = open(argv[1], O_RDONLY)) == -1){
        fprintf(stderr, "Couldn't open file\n");
        return -1;       
    }

    printf("fd = %d\n", fd);
    memset(buff, 0, BUFFSIZE);
    while ((n = read(fd, buff, BUFFSIZE)) > 0) {
        if (write(1, buff, BUFFSIZE) == n) {
            fprintf(stderr, "Error writing\n");
            return 1;
        }
    }
    return 0;
}