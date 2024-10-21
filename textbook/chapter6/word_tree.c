#include <stdio.h>
#define MAXWORD 20
#define LETTER 'a'
#define DIGIT 1
#include <string.h>
#include "alloc.h"


int char_types[256];
void initialise_char_types() {
    int i;
    for (int i = 'a'; i <= 'z'; i++) {
        char_types[i] = LETTER;
    }

    for (int i = '0'; i <= '9'; i++) {
        char_types[i] = DIGIT;
    }
}

char *strsave(char *s) {
  char *p;
  p = (char *) (alloc(strlen(s) + 1));
  if (p != NULL) {
    strcpy(p, s);
  }
  return p;
}


int get_word(char *w, int lim) 
{
    int c, t;
    if (char_types[c = *w++ = getchar()] != LETTER) {
        *w = '\0';
        return(c);

    }

    while (--lim > 0) {
        t = char_types[c = *w++ = getchar()];
        if (t != LETTER && t != DIGIT) {
            break;
        }
    }
    *(w-1) = '\0';
    return (LETTER);
}


struct tnode { /* the basic node */
    char *word; /* points to the text */
    int count; /* number of occurrences */
    struct tnode *left; /* left child */
    struct tnode *right; /* right child */
};

struct tnode *talloc()
{
  char *alloc(int n);

  return((struct tnode *) alloc(sizeof(struct tnode)));
}


struct tnode *tree(struct tnode *p, char *w) 
{
  struct tnode *talloc();
  char *strsave(char *w);
  int cond;

  if (p != NULL) {
    cond = strcmp(p->word, w);
    printf("word = %s, node = %s, cmp = %d\n", w, p->word, cond);
  }

  if (p == NULL) {    /* a new word has arrived */
    p = talloc();     /* make a new node */
    p->word = strsave(w);
    p->count = 1;
    p->left = p->right = NULL;
  } else if ((cond = strcmp(w, p->word)) == 0)
    p->count++;       /* repeated word */
  else if (cond < 0)  /* lower goes into left subtree */
    p->left = tree(p->left, w);
  else        /* greater into right subtree */
    p->right = tree(p->right, w);
  return (p);
}

void treeprint(struct tnode *p) /* print tree p recursively */
{
    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}

int main() /* word frequency count */
{
  struct tnode *root;
  char word [MAXWORD];
  int t;
  initialise_char_types();

  root = NULL;
  while ((t = get_word(word, MAXWORD)) != EOF)
    if (t == LETTER)
      root = tree(root, word);
  treeprint(root);
  return 0;
}
