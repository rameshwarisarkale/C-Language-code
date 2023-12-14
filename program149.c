#include<stdio.h>
#include<stdlib.h>         

// Structure declaration
struct node
{
    int data;                                               // 4 byte
    struct  node*next;                                      // 8 byte  self refrential structure
};
typedef struct node NODE;
typedef struct node*PNODE;
typedef struct node**PPNODE;

void InsertFirst(PPNODE Head ,int No)
{
    PNODE newn=NULL;             //pointer points to nothing
    newn=(PNODE)malloc(sizeof(NODE));  //allocate the memory

    newn->data=No;
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