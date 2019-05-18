#include <stdio.h> 
#include <stdlib.h> 
#include "ternary_search_tree.h"

#define MAX 50 

struct tst* new_node(char ch) 
{ 
    struct tst* tst = (struct tst*) malloc(sizeof( struct tst )); 
    tst->ch = ch; 
    tst->ending = 0; 
    tst->left = NULL;
    tst->eq = NULL;
    tst->right = NULL; 
    return tst; 
} 
  
void insert(struct tst** tree, char *word) 
{ 
    if (!(*tree)) 
        *tree = new_node(*word); 
    if ((*word) < (*tree)->ch) 
        insert(&((*tree)->left ), word); 
    else if ((*word) > (*tree)->ch) 
        insert(&((*tree)->right ), word); 
    else { 
        if (*(word+1)) 
            insert(&((*tree)->eq), word+1); 
        else
            (*tree)->ending = 1; 
    } 
} 

int search(struct tst *tree, char *word) 
{ 
    if (!tree) 
        return 0; 
    if (*word < (tree)->ch) 
        return search(tree->left, word); 
    else if (*word > (tree)->ch) 
        return search(tree->right, word); 
    else { 
        if (*(word+1) == '\0') 
            return tree->ending; 
  
        return search(tree->eq, word+1); 
    } 
} 

int isFree_node(struct tst *tree) 
{ 
    if (tree->left || tree->eq || tree->right) 
        return 0; 
    return 1; 
} 

int delete_node(struct tst *tree, char str[], int level) 
{ 
    if (tree == NULL) 
        return 0; 
    if (str[level+1] == '\0') { 
        if (tree->ending == 1) { 
            tree->ending = 0; 
            return isFree_node(tree); 
        } 
        else
            return 0; 
    } 
    else { 
        if (str[level] < tree->ch) 
            delete_node(tree->left, str, level); 
        else if (str[level] > tree->ch) 
            delete_node(tree->right, str, level); 
        else if (str[level] == tree->ch) { 
            if (delete_node(tree->eq, str, level+1)) { 
                free(tree->eq); 
                tree->eq = NULL;
                return !tree->ending && isFree_node(tree); 
            } 
        } 
    }   
    return 0; 
} 

// void traverseTST(struct tst* tree) 
// { 
//     char buffer[MAX]; 
//     traverse(tree, buffer, 0); 
// } 

// void traverse(struct tst* tree, char* buffer, int depth) 
// { 
//     if (tree) 
//     { 
//         traverse(tree->left, buffer, depth); 
  
//         buffer[depth] = tree->ch; 
//         if (tree->ending) 
//         { 
//             buffer[depth+1] = '\0'; 
//             printf( "%s\n", buffer); 
//         } 
  
//         traverse(tree->eq, buffer, depth + 1); 
  
//         traverse(tree->right, buffer, depth); 
//     } 
// } 