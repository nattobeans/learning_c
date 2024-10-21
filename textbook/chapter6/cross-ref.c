#include <stdio.h>
#include <string.h>
#define LINESIZE 1000
#include "alloc.h"


char *strsave(char *sp) {
    char *alloc(int n);
    // forgot to add one to the length and spent 5 hours debugging it
    // Kill me
    char *newp = (char *) alloc(strlen(sp) + 1);
    if (sp != NULL) {
        strcpy(newp, sp);
    }

    return newp;
}

#define LETTER 'a'
char char_types[256] = {
    ['a' ... 'z'] = LETTER,
    ['A' ... 'Z'] = LETTER
};


int get_word(FILE *fp, char *word, int *lineNumber) {
    char c;
    while((c = fgetc(fp)) != EOF) {
        if (c == '\n') {
            (*lineNumber)++;
        }
        if (char_types[c] != LETTER) {
            *word = '\0';
            return 1;
            break;
        }
        *word++ = c;
    }
    return 0;
    
}


struct tnode {
    char *word;
    int count;
    int lineOccurance[10];
    struct tnode *left;
    struct tnode *right;
};


struct tnode *tree(struct tnode *tp, char *word, int lidx) {
    struct tnode *talloc();
    int cmp, *lo;

    if (tp == NULL) {
        tp = talloc();
        tp->word = strsave(word);
        tp->count = 1; 
        tp->lineOccurance[0] = lidx;
        tp->lineOccurance[1] = -1;
        tp->left = tp->right = NULL;

    } else if ((cmp = strcmp(tp->word, word)) == 0) {
        tp->count++;   
        int i = 0;
        while (tp->lineOccurance[i] != -1) {
            if (tp->lineOccurance[0] == lidx) {
                break;
            }
            i++;
        }
        if (tp->lineOccurance[i] == -1) {
            tp->lineOccurance[i++] = lidx;
            tp->lineOccurance[i] = -1;
        }
    } else if(cmp < 0) {
        tp->left = tree(tp->left, word, lidx);
    } else {
        tp->right = tree(tp->right, word, lidx);
    }
    return (tp);
}


struct tnode *talloc() {
    char *alloc(int n);

    return (struct tnode *) alloc(sizeof(struct tnode));
}

void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size && arr[i] != -1; i++) {
        printf("%d", arr[i]);
        if (i < size - 1 && arr[i+1] != -1) {
            printf(", "); 
        }
    }
    printf("]\n");
}

void print_tree(struct tnode *tp) {
    char line[100];
    if (tp != NULL) {
        print_tree(tp->left);
        printf("Node: %s, Count: %d, Lines Present: ", tp->word, tp->count);
        printArray(tp->lineOccurance, sizeof(tp->lineOccurance));

        print_tree(tp->right);
    }
}


int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) {
        perror("Supply valid file path\n");
        return 1;
    }

    int get_word(FILE *fp, char *word, int *lineNumber);
    struct tnode *tree(struct tnode *tp, char *linep, int lidx);

    struct tnode *root;
    char *word, *lp;
    int len, lidx;
    
    root = NULL;
    word = (char *) alloc(1024);
    lidx = 1;
    printf("START\n");

    while ((get_word(fp, word, &lidx))) {
        if(*word == '\0')
            continue;

        root = tree(root, word, lidx);
    }
    print_tree(root);
    return 0;
}
