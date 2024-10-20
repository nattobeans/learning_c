#include <stdio.h>


int main() {
  	char c, line[100], *lp;
    lp = line;
    printf("Enter line\n");
  	while ((c = getchar()) != '\n' && c != '\0') {
    	*lp++ = c;
    }
  	printf("Line: %s\n", line);
    return 0;
}