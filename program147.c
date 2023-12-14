#include<stdio.h>
#include<stdlib.h>         


// Structure declaration
struct Node
{
    int data;                                               // 4 byte
    struct  node*next;                                      // 8 byte  self refrential structure
};

typedef struct node NODE;
typedef struct  node*PNODE;
typedef struct node**PPNODE;

int main()
{
    struct node*First=NULL;
    

    return 0;
}