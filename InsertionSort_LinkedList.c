#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#define SIZE 8
/*--------------------
Structure
--------------------*/
struct list
{
    int num;
    struct list * next;
};
typedef struct list node;
typedef node *link;

/*--------------------
Global Variable
--------------------*/

link head=NULL;
link sorted=NULL;

/*--------------------
Function 
--------------------*/
void push(int key);
void InsertionSort(link head);
void Insert(link newnode);
void printlist(link head);
int main(void)
{
    int i;
    link ptr;
    
    push(8);
    push(1);
    push(78);
    push(4);
    push(12);

    printf("Linked List before sorting:\n");
    printlist(head);
    printf("\n");

    InsertionSort(head);

    printf("Linked List after sorting:\n");
    printlist(sorted);
    system("pause");
    return 0;
}

void push(int key)
{
    link  newnode;
    newnode=(link)malloc(sizeof(node));
    newnode->num=key;
    newnode->next=head;
    head=newnode;
}
void InsertionSort(link head)
{
    link Element=head;
    while(Element!=NULL)
    {
        link NextElement=Element->next;
        Insert(Element);
        Element=NextElement;
    }
}
void Insert(link newnode)
{
    if(sorted==NULL || newnode->num<sorted->num)
    {
        newnode->next=sorted;
        sorted=newnode;
    }
    else
    {
        link current=sorted;
        while(current->next!=NULL && newnode->num>current->next->num)
            current=current->next;
        newnode->next=current->next;
        current->next=newnode;
    }
}
void printlist(link head)
{
    link ptr=head;
    while(ptr!=NULL)
    {
        printf("%3d",ptr->num);
        ptr=ptr->next;
    }
}