#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    stuct node*next;
};
typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node** PPNODE;

void Push(PPNODE Head,int no)
{
    

}
int Pop(PPNODE Head)
{

}
void Display(PNODE Head)
{
    printf(" Contents of Linked List:\n");

    while(Head!=NULL)
    {
        printf(" |%d| ->", Head->data);
        Head=Head->next;
    }
    printf("NULL\n");
}
int pop(PPNODE Head,)
{
    int value=0;

    if(*Head==NULL)
    {
        printf("stack is empty");

    }
    else
    {

    }
}
int main()
{

    PNODE first=NULL;
    int iRet=0;
    Push(&first,101);
    Push(&first,51);
    Push(&first,21);
    Push(&first,11);
    int iRet=0;

    Display(first);
    iRet=Push(&first);
    printf("poped elements are%d\n",iRet);


    return 0;

}