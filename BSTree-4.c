#include <assert.h>
#include "BSTree-4.h"
#include <math.h>


/*Det är helt tillåtet att lägga till egna hjälpfunktioner men de befintliga
funktionerna ska implementeras enligt instruktionerna*/
/* Statiska hjälpfunktioner används av andra funktioner i trädet och ska inte ligga
i interfacet (användaren behöver inte känna till dessa) */
/* Skapar en trädnod med det givna datat. Denna funktion bör vara den enda som
använder malloc för att skapa en ny treeNode*/





static struct treeNode* create_tree_node(int data)
{

    struct treeNode *ptr = malloc(sizeof(struct treeNode));
    if (ptr == NULL)
    {
        return 0;
    }

    ptr->data = data;
    ptr->right = NULL;
    ptr->left = NULL;
    return ptr;

}


static int* write_sorted_to_array(const BSTree tree) 
{
   
    int size = number_of_nodes(tree);
    int *ptr = (int*)malloc(size * sizeof(int));
    int i = 0;
    array_helper(ptr, tree, &i);
    return ptr;
    
}


static void build_tree_sorted_from_array(BSTree* tree, const int arr[], int size)
{
    
    if(size <= 0)
    {
        return;
    }
    insert_sorted(tree, arr[size/2]);
    build_tree_sorted_from_array(tree, arr, size/2);
    build_tree_sorted_from_array(tree, arr + size/2 + 1, size - size/2 - 1);
    



/* Bygg rekursivt från mitten.
Mittenelementet i en delarray skapar rot i delträdet
Vänster delarray bygger vänster delträd
Höger delarray bygger höger delträd*/

}

/* Returnerar en dynamiskt allokerad array som innehåller trädets data sorterat */


/* Skapa en dynamisk array med rätt storlek
Skriv datat från trädet sorterat till arrayen (minsta till största)
- till detta kanske du behöver en hjälpfunktion */


/* Bygger upp ett sorterat, balanserat träd från en sorterad array */

/* Implementation av trädet, funktionerna i interfacet */
/* Skapar ett tomt träd - denna funktion ar färdig */

BSTree create_empty_tree(void)
{

return NULL;

}
/* Returnerar 1 ifall trädet är tomt, 0 annars */
int is_empty(const BSTree tree)
{
 if(tree == NULL)
 {
    return 1;
 }
 return 0;
}




/* Sätter in 'data' sorterat i *tree */
void insert_sorted(BSTree* tree, int data)
{
    if(*tree != NULL)
    {
        if(data == (*tree)->data)
        {
            return;
        }
        if(data < (*tree)->data)
        {
            insert_sorted(&(*tree)->left, data);
        }
        else if(data > (*tree)->data)
        {
            insert_sorted(&(*tree)->right, data);
        }

    }
    else
    {
        *tree = create_tree_node(data);
    }
    
/*Tänk på att trädet kan vara tomt vid insättning
I vanliga fall kan man lösa dubletter på olika sätt. Eftersom vi vill att era
lösningar
fungerar likadant inför examinationen så bestämmer jag att dubletter ej ska
tillåtas i trädet.
Post-condition kan verifieras med hjälp av find(...)*/

}


/* Utskriftsfunktioner
Det räcker att ni implementerar LR-ordningarna*/
void print_preorder(const BSTree tree)
{
    if(tree != NULL)
    {
        
        send_int(tree->data);
        if(tree->left != NULL)
        {
            print_preorder(tree->left);
        }
        if(tree->right != NULL)
        {
            print_preorder(tree->right);
        }
    }

}




void print_inorder(const BSTree tree)
{
    if(tree != NULL)
    {
        //nylista skapas varjegång. 
        if(tree->left != NULL)
        {
            print_inorder(tree->left);
            
        }
        send_int(tree->data);
        if(tree->right != NULL)
        {
            print_inorder(tree->right);
        }
    }
}




void print_postorder(const BSTree tree)
{
    
    if(tree != NULL)
    {
        if(tree->left != NULL)
        {
            print_postorder(tree->left);
        }
        if(tree->right != NULL)
        {
            print_postorder(tree->right);
        }
        send_int(tree->data);
    }
}





/* Returnerar 1 om 'data' finns i tree, 0 annars */
int find(const BSTree tree, int data)
{
   
  
    if(tree != NULL)
    {
        if(data > tree->data)
        {
            find(tree->right, data);
        }
        if(data < tree->data)
        {
            find(tree->left, data);
        }
        if(tree->data == data)
        {
           
            return 1;
        }
    }
    else
    {
   
        return 0;
    }
    
// Tänk pa att trädet kan vara tomt

}





/* Tar bort 'data' från trädet om det finns */
void remove_element(BSTree* tree, int data)
{
    if(*tree != NULL)
    {
        if(data > (*tree)->data)
        {
            remove_element(&(*tree)->right, data);
        }
        if(data < (*tree)->data)
        {
            remove_element(&(*tree)->left, data);
        }
        if((*tree)->data == data)
        {
            if((*tree)->left == NULL && (*tree)->right == NULL)
            {
                free(*tree);
                *tree = NULL;
            }
            else if((*tree)->left != NULL && (*tree)->right != NULL)
            {
                (*tree)->data = min_value_data(&(*tree)->right);
                remove_element(&(*tree)->right, (*tree)->data);
            }
            else if((*tree)->left != NULL)
            {
                (*tree)->data = (*tree)->left->data;
                remove_element(&(*tree)->left, (*tree)->data);
            }
            else if((*tree)->right != NULL)
            {
                (*tree)->data = (*tree)->right->data;
                remove_element(&(*tree)->right, (*tree)->data);

            }
        
        

        }

    }

/* Inget data ska/kan tas bort från ett tomt träd
Tre fall: Ett löv (inga barn), ett barn (vänster eller höger), två barn
Glöm inte att frigöra noden när den länkats ur trädet'*/

}




/* Returnerar hur många noder som totalt finns i trädet */
int number_of_nodes(const BSTree tree)
{
    if(tree != NULL)
    {
        
       return 1 + number_of_nodes(tree->left) + number_of_nodes(tree->right);
    }
   
    
    
}




/* Returnerar hur djupt trädet är */
int depth(const BSTree tree)
{
    if(tree != NULL)
    {
        int max_depth = 0;
        int left = depth(tree->left);
        int right = depth(tree->right);
        if(left < right)
        {
            max_depth = right;
        }
        else
        {
            max_depth = left;

        }
        return 1 + max_depth;

    }
}




/* Returnerar minimidjupet för trädet
Se math.h för användbara funktioner*/
int min_depth(const BSTree tree)
{
    if(tree != NULL)
    {   

        return(log2(number_of_nodes(tree)) + 1);
    }
}









/* Töm trädet och frigör minnet för de olika noderna */
void free_tree(BSTree* tree)
{
    if(*tree != NULL)
    {
        if((*tree)->left != NULL)
        {
            free_tree(&(*tree)->left);
        }
        if((*tree)->right != NULL)
        {
            free_tree(&(*tree)->right);
        }
        free(*tree);
        *tree = NULL;
    }
    
}




int min_value_data(BSTree *tree)
{
    while((*tree)->left != NULL)
    {
        *tree = (*tree)->left;

    }
    return (*tree)->data;

}


void array_helper(int* ptr, BSTree tree, int* i) 
{
    if(tree->left != NULL) 
    {
        array_helper(ptr, tree->left, i);
    }

    ptr[*i] = tree->data;
    *i = *i + 1;

    if(tree->right != NULL) 
    {
        array_helper(ptr, tree->right, i);
    }
}

/* Balansera trädet så att depth(tree) == minDepth(tree) */
void balance_tree(BSTree* tree)
{
    int size = number_of_nodes(*tree);
    int *ptr = write_sorted_to_array(*tree);
    free_tree(tree);
    build_tree_sorted_from_array(tree, ptr, size);
   

/* Förslag på algoritm:
- överfor trädet till en dynamiskt allokerad array med writeSortedToArray()
- töm trädet med freeTree()
- bygg upp trädet rekursivt från arrayen med buildTreeSortedFromArray()
- frigör minne för den dynamiskt allokerade arrayen
Post-conditions:
- tree har lika många noder som tidigare
- djupet för trädet är samma som minimumdjupet för trädet */

}

