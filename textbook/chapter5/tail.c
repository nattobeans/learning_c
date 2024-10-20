#include <stdio.h>

#define DEFAULT_PRINT_LENGTH 10

int tail_print(FILE *fp, int print_length) {
    char *out[100];
    char line_arr[1000000];
    char *start_line, *line;
    int c, out_len = 1, oidx = 0;

    line = line_arr;
    start_line = line;
    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') {
            *line++ = '\0';
            out[oidx++] = start_line;
            start_line = line;
            out_len++;
        } else {
            *line++ = c;
        }
    }
    
    if(*(line-1) != '\n') {
        *line++ = '\0';
        out[oidx++] = start_line;
    }

    
    if (oidx - print_length > 0) {
        oidx -= print_length;
    } else {
        oidx = 0;
    }

    while (oidx < out_len) {
        printf("%s\n", out[oidx++]);
    }

    return 0;
}


int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please pass in arguments\n");
        return 1;
    }

    FILE *fp = fopen(*++argv, "r");
    if (fp == NULL) {
        printf("Not valid filename\n");
        return 1;
    }
    
    int print_length=-1, cast_worked, exit_code;
    char *flags;
    int i=0;
    while (--argc > 1 && (*++argv)[0] == '-') {
        for (flags = argv[0]+1; *flags != '\0'; flags++) {
            if (*flags == 'n' && argc > 1) {
                cast_worked = sscanf((argv[1]), "%d", &print_length);
                if (!cast_worked) {
                    printf("Invalid number %d\n", print_length);
                    break;
                }
            }
        }
    }
    if (print_length == -1) {
        print_length = DEFAULT_PRINT_LENGTH;
    }

    exit_code = tail_print(fp, print_length);
    fclose(fp);

    return exit_code;
}