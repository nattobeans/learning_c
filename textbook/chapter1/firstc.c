#include <stdio.h>
// I am a comment
/* I am commen t*/
int main() {
    printf("Hello World!\n");
    printf("Answer %d\n", 42);
    printf("Name %s\n", "Josh");
    printf("x %.1f i %d\n", 3.46, 100);
    int usf, euf;
    printf("Enter floor\n");
    scanf("%d", &usf);
    euf = usf - 1;
    printf("%d\n", euf);
    

    char name[101];
    printf("Enter a name: ");
    scanf("%100s", name);

    printf("%s\n", name);


    char line[10000];
    FILE *hand;
    hand = fopen("romeo.txt", "r");
    while(fgets(line, 100, hand) != NULL) {
        printf("%s", line);
    }
    int i;
    for(i=0; i<5; i++) {
        printf("%d\n", i);
    }
    fclose(hand);
    return 0;
}