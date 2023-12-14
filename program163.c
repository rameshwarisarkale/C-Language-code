#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node*next;

}NODE,*PNODE,**PPNODE;

// typedef struct node NODE;
// typedef struct node* PNODE;
// typedef struct node** PPNODE;


void InsertFirst(PPNODE Head,PPNODE Tail,int no)
{
    PNODE newn=*Head;
    newn=(PNODE)malloc(sizeof(NODE));

    newn->data=no;
    newn->next=NULL;

    if((*Head==NULL) && (*Tail==NULL))    //LL is empty
    {
        *Head=newn;
        *Tail=newn;
        // (*Tail)->next=*Head;               //circular LL statement
    }
    else                                  // LL contains atleast one node
    {
        newn->next=*Head;
        *Head=newn;
        // (*Tail)->next=*Head;

    }
    (*Tail)->next=*Head;                   // Common statement
}

void InsertLast(PPNODE Head,PPNODE Tail,int no)
{

    PNODE newn=*Head;
    newn=(PNODE)malloc(sizeof(NODE));

    newn->data=no;
    newn->next=NULL;

    if((*Head==NULL) && (*Tail==NULL))    //LL is empty
    {
        *Head=newn;
        *Tail=newn;
        // (*Tail)->next=*Head;               //circular LL statement
    }
    else                                  // LL contains atleast one node
    {
        (*Tail)->next=newn;
        *Tail=newn;
        // (*Tail)->next=*Head;
    }
    (*Tail)->next=*Head;                        // common statement
}


void DeleteFirst(PPNODE Head,PPNODE Tail)
{
    if((*Head==NULL)  &&  (*Tail==NULL)) //Empty LL
    {
        return ;
    }
    else if(*Head==*Tail)               //single node
    {
        free(*Head);
        *Head=NULL;
        *Tail=NULL;
    }
    else
    {
        (*Head)=(*Head)->next;
        free((*Tail)->next);
        (*Tail)->next=*Head;
        
    }
}

void DeleteLast(PPNODE Head,PPNODE Tail)
{
    PNODE temp=*Head;
    if((*Head==NULL)  &&  (*Tail==NULL)) //Empty LL
    {
        return ;

    }
    else if(*Head==*Tail)               //single node
    {
        
        free(*Head);
        *Head=NULL;
        *Tail=NULL;
    }
    else
    {
        while (temp->next!=*Tail)
        {
            temp=temp->next;
        }
        free(*Tail);
        *Tail=temp;
        (*Tail)->next=*Head;
        
    }

}
void Display(PNODE Head,PNODE Tail)
{
    printf("elements of linked list are:\n");

    if((Head!=NULL) &&(Tail!=NULL))
    {
        do
        {
            printf("|%d|->",Head->data);
            Head=Head->next;
        } while (Head!=Tail->next);
        printf("Adress of first node\n");  
    }
}
int Count(PNODE Head,PNODE Tail)
{
    int iCnt=0;

    if((Head!=NULL) &&(Tail!=NULL))
    {
        do
        {
            Head=Head->next;
            iCnt++;
        } while (Head!=Tail->next);
    }
    return iCnt;
}
void InsertAtPos(PPNODE Head,PPNODE Tail,int no,int ipos)
{
    int size=0;
    size=Count(*Head,*Tail);
    PNODE newn=NULL;
    PNODE temp=*Head;
    int i=0;

    if((ipos<1) || (ipos>size+1))
    {
        printf("invalid position");
        return ;
    }
    if(ipos==1)
    {
        InsertFirst(Head,Tail,no);
    }
    else if(ipos==size+1)
    {
        InsertLast(Head,Tail,no);
    }
    else
    {
        newn=(PNODE)malloc(sizeof(NODE));
        newn->data=no;
        newn->next=NULL;

        for(i=1;i<ipos-1;i++)
        {
            temp=temp->next;
        }
        newn->next=temp->next;
        newn->next=temp;
    }
}
void DeleteAtPos(PPNODE Head,PPNODE Tail,int ipos)
{
    int size=0;
    size=Count(*Head,*Tail);
    PNODE temp=*Head;
    int i=0;
    PNODE targetednode=*Head;

    if((ipos<1) || (ipos>size))
    {
        printf("invalid position");
        return ;
    }
    if(ipos==1)
    {
        DeleteFirst(Head,Tail);
    }
    else if(ipos==size)
    {
        DeleteLast(Head,Tail);
    }
    else
    {
        for(i=1;i<ipos-1;i++)
        {
            temp=temp->next;
        }
        targetednode=temp->next;
        temp->next=temp->next->next;
        free(targetednode); 
    }
}
int main()
{
    PNODE First=NULL;
    PNODE Last=NULL;                    //#     
    int iRet=0;

    InsertFirst(&First,&Last,51);
    InsertFirst(&First,&Last,21);
    InsertFirst(&First,&Last,11);

    InsertLast(&First,&Last,101);
    InsertLast(&First,&Last,111);
    InsertLast(&First,&Last,121);

    Display(First,Last);
    iRet=Count(First,Last);
    printf("number of elements are:%d\n",iRet);

    DeleteFirst(&First,&Last);
    Display(First,Last);
    iRet=Count(First,Last);
    printf("number of elements are:%d\n",iRet);

    DeleteLast(&First,&Last);
    Display(First,Last);
    iRet=Count(First,Last);
    printf("number of elements are:%d\n",iRet);

    InsertAtPos(&First,&Last,105,5);
    Display(First,Last);
    iRet=Count(First,Last);
    printf("number of elements are:%d\n",iRet);

    DeleteAtPos(&First,&Last,5);
    Display(First,Last);
    iRet=Count(First,Last);
    printf("number of elements are:%d\n",iRet);

    return 0;
}