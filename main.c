#include <stdio.h> 
#include "ternary_search_tree.h"

int main() 
{ 
    struct tst *root = NULL; 
  
    insert(&root, "art"); 
    insert(&root, "cat"); 
    insert(&root, "cats"); 
    insert(&root, "up"); 
    insert(&root, "bug");

    printf("\nОбход по дереву\n"); 
    // traverseTST(root); 

    printf("\nУдаление слова 'cats'\n");
    delete_node(root ,"cats" , 0);

    printf("\nОбход по дереву\n"); 
    // traverseTST(root); 

    // printf("\nПоиск слов\n"); 
    // printf("'cats':");
    // searchTST(root, "cats")? printf("Найдено\n"): printf("Не найдено\n"); 
    // printf("'bu':");
    // searchTST(root, "bu")?   printf("Найдено\n"): printf("Не найдено\n"); 
    // printf("'cat':");
    // searchTST(root, "cat")?  printf("Найдено\n"): printf("Не найдено\n"); 
  
    return 0; 
} 
