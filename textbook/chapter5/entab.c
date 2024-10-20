//         #include <stdio.h>
// #include <string.h>

// #define TABSIZE 8
// #define BUFFER_SIZE 1064


// void entab(FILE *fp_read, FILE *fp_out) {
//     int c, pos=1, spc_cnt=0;
//     while ((c = fgetc(fp_read)) != EOF) {
//         printf("%d\n", pos);
//         if (c == ' ') {
//             spc_cnt++;
//             if (pos == 8) {
//                 fputc('\t', fp_out);
//                 spc_cnt = 0;
//             }
//         } else {
//             while (spc_cnt-- > 0) {
//                 fputc(' ', fp_out);
//             }
//             fputc(c, fp_out);
//             pos = (c == '\n') ? 1 : pos + 1;
//         }
//     }
//     fputc('\n', fp_out);
// }

// int main(int argc, char *argv[]) {
//     if (argc < 2) {
//         printf("please supply arguments\n");
//         return 1;
//     }

//     FILE *fp = fopen(*++argv, "r+");
//     if (fp == NULL) {
//         printf("supply valid file path\n");
//         return 1;
//     }
//     char c, line[BUFFER_SIZE], *line_ptr = line, tab_line[BUFFER_SIZE];
//     int i = 0, lim;

//     entab(fp, stdout);
//     return 0;
// }


#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_TAB_WIDTH 8

// Function to determine the next tab stop based on current position and tab stops array
int next_tab_stop(int position, int *tabstops, int tab_count) {
    for (int i = 0; i < tab_count; ++i) {
        if (position < tabstops[i])
            return tabstops[i];
    }
    return position + DEFAULT_TAB_WIDTH;
}

// Function to replace spaces with tabs
void entab(FILE *input, FILE *output, int *tabstops, int tab_count) {
    int c, position = 1, space_count = 0;

    while ((c = fgetc(input)) != EOF) {
        if (c == ' ') {
            space_count++;
            if (position == next_tab_stop(position, tabstops, tab_count)) {
                fputc('\t', output);
                space_count = 0;
            }
        } else {
            while (space_count > 0) {
                fputc(' ', output);
                space_count--;
            }
            fputc(c, output);
            position = (c == '\n') ? 1 : position + 1;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_file> [tab_stops...]\n", argv[0]);
        return 1;
    }

    // Open the input file for reading
    FILE *input = fopen(argv[1], "r");
    if (input == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read tab stops from the command-line arguments if provided
    int tabstops[argc - 2];
    int tab_count = 0;
    for (int i = 2; i < argc; ++i) {
        tabstops[tab_count++] = atoi(argv[i]);
    }

    // If no tab stops are provided, set default tab stops every 8 columns
    if (tab_count == 0) {
        tabstops[0] = DEFAULT_TAB_WIDTH;
        tab_count = 1;
    }

    // Process the input file and write to stdout
    entab(input, stdout, tabstops, tab_count);

    // Close the input file
    fclose(input);

    return 0;
}
