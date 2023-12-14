#include<stdio.h>
#include<stdlib.h>         


// Structure declaration
struct Node
{
    int data;                                               // 4 byte
    struct  node*next;                                      // 8 byte  self refrential structure
};

typedef struct node NODE;
typedef struct node*PNODE;
typedef struct node**PPNODE;

void InsertFirst(PPNODE Head ,int iNo)
{
    struct node* newn=NULL;             //pointer points to nothing
    newn=(strut node*)malloc(sizeof(NODE));  //allocate the memory

    new->data=No;
    newn->next=NULL;

}
int main()
{
   PNODE First=NULL;

   InsertFirst(&First,51);
   InsertFirst(&First,21);
   InsertFirst(&First,11);
    
    return 0;
}