#include <stdio.h>
#include <string.h>
#define MAX_INPUT 100

int main() {
    printf("Enter two strings\n");
  	char s1[MAX_INPUT], s2[MAX_INPUT], res[MAX_INPUT * 2];
  	fgets(s1, MAX_INPUT, stdin);
  	
  	char *sp1, *sp2, *rp;
  	rp = res;
  	sp1 = s1;
  	while(*sp1 != '\0') {
      	printf("%c\n", *sp1);
      	if (*sp1 == '\n') {
            sp1++;
            continue;
        }   
    	*rp++ = *sp1++;
    }
  	*rp++ = ' ';
  	*rp++ = '&';    
  	*rp++ = ' ';
	
  	fgets(s2, MAX_INPUT, stdin);
    sp2 = s2;
  	while(*sp2 != '\0') {
      	printf("%c\n", *sp2);
      	if (*sp2 == '\n') {
            sp2++;
            continue;
        }  
    	*rp++ = *sp2++;
    }
  
  	printf("%s\n", res);
}