#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Please input 2 filenames: `%s <File 1> <File 2>`\n", argv[0]);
        return 1;
    }

    FILE *fp1, *fp2;

    fp1 = fopen(argv[1], "r");
    fp2 = fopen(argv[2], "r");
    if (fp1 == NULL || fp2 == NULL) {
        fprintf(stderr, "One of these files (possibly both knowing u) isn't readable. I'm not telling u which one cause I am too lazy.\n");
        return 1;
    }

    int ln, col;
    char c1, c2;

    flockfile(fp1);
    flockfile(fp2);
    ln = 1;
    col = 1;
    while ((c1 = getc_unlocked(fp1)) != EOF && (c2 = getc_unlocked(fp2)) != EOF) {
        if (c1 != c2)
            break;

        if (c1 == '\n') {
            ln++;
            col = 1;
        } else {
            col++;
        }
    }
    funlockfile(fp1);
    funlockfile(fp2);
    fclose(fp1);
    fclose(fp2);

    //if header is same deal with it;
    if (c1 == EOF)
        c2 = getc_unlocked(fp2);
    else if (c2 == EOF)
        c1 = getc_unlocked(fp1);

    
    if (c1 == EOF && c2 == EOF)
        printf("File: %s && File: %s are equal!\n", argv[1], argv[2]);
    else if (c1 == EOF)
        printf("File: \"%s\" was equal to File: \"%s\" upto line %d and col %d\n",  argv[1], argv[2], ln, col);
    else if (c2 == EOF)
        printf("File: \"%s\" was equal to File: \"%s\" upto line %d and col %d\n",  argv[2], argv[1], ln, col);
    else
        printf("File: \"%s\" was equal to File: \"%s\" upto line %d, col %d\n", argv[1], argv[2], ln, col);

    return 0;
}