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
        // printf("%c", c);
        if (c == '\n') {
            (*lineNumber)++;
            printf("line NUMMMMM = %d\n", *lineNumber);
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


// struct tnode *tree(struct tnode *tp, char *word, int lidx) {
//     struct tnode *talloc();
//     int cmp, *lo;
    
//     if (tp != NULL) {
//         cmp = strcmp(tp->word, word);
//         printf("word = %s, node = %s, cmp = %d\n", word, tp->word, cmp);
//     }

//     if (tp == NULL) {
//         printf("HELLO %s\n", word);
//     }

//     if (tp == NULL) {
//         printf("allocatiing %s\n", word);
//         tp = talloc();
//         tp->word = strsave(word);
//         tp->lineOccurance[0] = lidx;
//         tp->lineOccurance[1] = -1;
//         tp->left = tp->right = NULL;

//     } else if (cmp == 0) {
//         lo = tp->lineOccurance;
//         while (*lo != -1) {
//             if (*lo == lidx) {
//                 break;
//             }
//             lo++;
//         }
//         if (*lo != lidx) {
//             *lo++ = lidx;
//             *lo = -1;
//         }
//     } else if(cmp < 0) {
//         printf("left\n");
//         tree(tp->left, word, lidx);
//     } else {
//         printf("right\n");
//         tree(tp->right, word, lidx);
//     }
//     return (tp);
// }

struct tnode *tree(struct tnode *p, char *w, int lidx) 
{
  struct tnode *talloc();
  char *strsave(char *w);
  int cond;

//   if (p != NULL) {
//     cond = strcmp(p->word, w);
//     printf("word = %s, node = %s, cmp = %d\n", w, p->word, cond);
//   }

  if (p == NULL) {    /* a new word has arrived */
    p = talloc();     /* make a new node */
    p->word = strsave(w);
    p->count = 1;
    p->lineOccurance[0] = lidx;
    p->lineOccurance[1] = -1;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0) {
    p->count++;   
    int i = 0;
    while (p->lineOccurance[i] != -1) {
        if (p->lineOccurance[0] == lidx) {
            break;
        }
        i++;
    }
    if (p->lineOccurance[i] == -1) {
        p->lineOccurance[i++] = lidx;
        p->lineOccurance[i] = -1;
    }
  } 
  else if (cond < 0)  /* lower goes into left subtree */
    p->left = tree(p->left, w, lidx);
  else        /* greater into right subtree */
    p->right = tree(p->right, w, lidx);
  return (p);
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
            printf(", ");  // Add comma and space between elements, but not after the last one
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
