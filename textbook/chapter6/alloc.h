#define ALLOCSIZE 1000000000 /* size of available space */

static char allocbuf[ALLOCSIZE]; /* storage for alloc */
static char *allocp = allocbuf;  /* next free position */

char  *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocp >= n) {  /* if it fits */
        allocp += n;
        return allocp - n; /* old p */
    } else          /* not enough room */
        return 0;
}