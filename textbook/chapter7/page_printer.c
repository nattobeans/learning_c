#include <stdio.h>
#define MAXLEN 100
void print_page(FILE *fp) {
    char line[MAXLEN], *lp;
    while (fgets(line, MAXLEN, fp)) {
        printf("%s", line);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Supply at least one filename: `%s <file 1> <file2> ...`", argv[1]);
        return 1;
    }

    int i;
    FILE *fp;
    for (i=1; i < argc; ++i) {
        printf("================== File %s, Page %d ==================\n", argv[i], i);
        fp = fopen(argv[i], "r");
        print_page(fp);
        printf("================== End Page ==================\n");
        if (i < argc-1)
            printf("------------------- Next Page -------------------\n");
    }
    
}