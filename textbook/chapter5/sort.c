#include <stdio.h>
#include <string.h>

#define LINES 100 
#define MAXLINE 1000
#define MAXLEN 1000

int get_line(char s[], int lim)
{
    int c, i;

    for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return(i);
}


int readlines(char *lineptr[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];
  void *alloc;
  nlines = 0;
  while ((len = get_line(line, MAXLEN)) > 0)
    if (nlines >= maxlines)
      return(-1);
    else if ((p = alloc(len)) == NULL)
      return(-1);
    else {
      line[len-1] = '\0'; /* zap newline */
      strcpy(p, line);
      lineptr[nlines++] = p;
    }
  return (nlines);
}


void writelines(char *lineptr[], int nlines)
{
  int i;

  for (i = 0; i < nlines; i++)
    printf("%s\n", lineptr[i]);
}


void swap(char *px[], char *py[])
{
  char *temp;

  temp = *px;
  *px = *py;
  *py = temp;
}

void sort(char *v[], int n, void (*comp)(), void (*exch)())
{
  int gap, i, j;

  for (gap = n/2; gap > 0; gap /= 2)
    for (i = gap; i < n; i++)
      for (j = i-gap; j >= 0; j -= gap) {
        if ((*comp)(v[j], v[j+gap]) <= 0)
          break;
        (*exch)(&v[j], &v[j+gap]);
      }
}

int main(int argc, char *argv[])
{
  char *lineptr[LINES]; 
  int nlines; 
  int strcmp(const char *s1, const char *s2), numcmp(const char *s1, const char *s2);
  void swap(char *px[], char *py[]);
  int numeric = 0; 

  if (argc>1 && argv[1][0] == '-' && argv[1][1] == 'n')
    numeric = 1;
  if ((nlines = readlines(lineptr, LINES)) >= 0) {
    if (numeric)
      sort(lineptr, nlines, numcmp, swap);
    else
      sort(lineptr, nlines, strcmp, swap);
    writelines(lineptr, nlines);
  } else {
      printf("input too big to sort\n");
      return 1;
  }
    return 0;
}