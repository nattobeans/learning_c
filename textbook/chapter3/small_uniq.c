#include <stdio.h>
#include <string.h>

int add_str_to_keep(char s[], char keep[], int kIdx) {
	int i = 0, j = 0, n = strlen(s);
  	while(i < n) {
    	keep[kIdx++] = s[i++];
    }
  	keep[kIdx++] = '\n';
  	return kIdx;
}

int cmp_keep(char line[], char keep[], int lineLens[], int n) {
  	int kIdx = 0, lineLen = strlen(line);
  	int i;
	for(i=0; i<n; i++) {	
    	int m = lineLens[i];
      	if (m != lineLen) {
          	kIdx += m+1;
        	continue;
        }
      	int lIdx = 0;
        int cmpCnt = 0;
      	while (lIdx < m) {
          if(line[lIdx++] != keep[kIdx++]) {
            break;
          } else {
          	cmpCnt++;
          }
        }
      	if (cmpCnt == m){
        	return 0;
        }
    }
  
    return 1;
}

int main() {
    char line[1000];
    char keep[1000];
  	int lineLens[100];
  	int lIdx = 0;
  
  	int first = 1, kIdx = 0;
  
    while(gets(line) != NULL ) {
  		if (lIdx == 0) {
        	lineLens[lIdx++] = strlen(line);
         	kIdx = add_str_to_keep(line, keep, kIdx);
          	continue;
        }
      if (cmp_keep(line, keep, lineLens, lIdx)) {
        kIdx = add_str_to_keep(line, keep, kIdx);
        lineLens[lIdx++] = strlen(line);
      } 
      	
    }
  keep[kIdx] = '\0';
  printf("%s\n", keep);
}