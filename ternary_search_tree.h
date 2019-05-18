#ifndef TERNARY_SEARCH_TREE_H
#define TERNARY_SEARCH_TREE_H

struct tst 
{ 
    unsigned int ending; 
    char ch; 
    struct tst *left, *eq, *right; 
}; 

struct tst* new_tst(char data);
void insert(struct tst** root, char *word);
void traverse(struct tst* root, char* buffer, int depth);
void traverseTST(struct tst* root);
int search(struct tst *root, char *word);
int delete_node(struct tst *root, char str[], int level); 
int isFree_node(struct tst *root); 

#endif