#include <stdio.h>
#include <string.h>
#define LINES 100
#define MAXLEN 1000


int get_line(char s[], int lim) 
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return(i);
}



int readlines(char *lineptr[], int maxlines, char lines[])
{
    int len, nlines, size;
    char *p, line[MAXLEN];
    p = lines;

    size = 0;
    nlines = 0;
    while ((len = get_line(line, MAXLEN)) > 0)
        if (nlines >= maxlines)
            return(-1);
        else if (size + len > MAXLEN)
            return(-1);
        else {
            line[len-1] = '\0'; 
            strcpy(p, line);
            lineptr[nlines++] = p;
            p += len;
        }
    return (nlines);
}

void writelines(char *lineptr[], int nlines) {
    int i;
    for (i=0; i<nlines; ++i) {
        printf("%s\n", lineptr[i]);
    }
}


int main() 
{
    char *lineptr[LINES];
    int nlines; 
    char lines[1000];

    nlines = readlines(lineptr, LINES, lines);
    printf("Num of lines entered = %d\n", nlines);
     if (nlines > 0) {
        printf("\nStarted printing lines\n");
        writelines(lineptr, nlines);
    }
    return 0;
}