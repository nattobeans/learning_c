#include <stdio.h>
#include <string.h>


void string_squeeze(char s[], char filter[]) {
    int i, j;
    for(i = j = 0; s[i] != '\0'; i++) {
        int isNotFiltered = 1;
        for(int k = 0; k < strlen(filter); k++) {
            if (s[i] == filter[k]) {
                isNotFiltered = 0;
            }
        }
        if(isNotFiltered) {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}


int main() {
    
    char s[] = "HELLOOOOO NEWYORK";
    char filter[] = "ONE";
    printf("Orig: %s\n", s);

    string_squeeze(s, filter);
    printf("NEw filtered: %s\n", s);
    
    return 0;
}