#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node*next;
};
typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node**PPNODE;

void InsertFirst(PPNODE Head,int No)
{
    PNODE newn=(PNODE)malloc(sizeof(NODE));

    newn->data=No;
    newn->next=NULL;

    if(*Head==NULL)
    {
        *Head=newn;
    }
    else
    {
        newn->next=*Head;
        *Head=newn;
    }
}
void InsertLast(PPNODE Head,int No)
{
    PNODE Temp=*Head;
    PNODE newn=(PNODE)malloc(sizeof(NODE));

    newn->data=No;
    newn->next=NULL;

    if(*Head==NULL)
    {
        *Head=newn;
    }
    else
    {
        while(Temp->next!=NULL)
        {
            Temp=Temp->next;
        }
        Temp->next=newn;
    }

}
void Display(PNODE Head)
{
    printf("contents of the linked list are:\n");

    while(Head!=NULL)
    {
        printf("| %d | -> ",Head->data);
        Head = Head->next;
    }
    printf("NULL\n");
}
void DeleteFirst(PPNODE Head)
{
    PNODE Temp=*Head;
    if(*Head==NULL)
    {
        return;
    }
    else if((*Head)->next==NULL)
    {
        free(*Head);
        *Head=NULL;
    }
    else
    {
        *Head=(*Head)->next;
        free(Temp);
    }
}
void DeleteLast(PPNODE Head)
{
    PNODE Temp=*Head;
    if(*Head==NULL)
    {
        return;
    }
    else if((*Head)->next==NULL)
    {
        free(*Head);
        *Head=NULL;
    }
    else
    {
        while(Temp->next->next!=NULL)
        {
            Temp=Temp->next;
        }
        free(Temp->next);
        Temp->next=NULL;
 
    }
}
int main()
{
    PNODE first=NULL;

    InsertFirst(&first,51);
    InsertFirst(&first,21);
    InsertFirst(&first,11);

    InsertLast(&first,61);

    DeleteFirst(&first);
    DeleteLast(&first);

    Display(first);
    return 0;

}