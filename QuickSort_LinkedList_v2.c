#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*--------------------
Structure
--------------------*/
struct list
{
    int data;
    struct list * next;
};
typedef  struct list node;
typedef  node * link;

/*--------------------
Global Variable
--------------------*/
link head=NULL;
/*--------------------
Function 
--------------------*/
void push(int key);
void display(link  head);
link FindTail(link head);
link partition(link head, link end,link* newHead,link* newEnd);
//link Partition(link first ,link last,link * newfirst_ref,link * newlast_ref);
link quickSortRecur(link head,link end);
void quickSort(link * headRef);


int main(void)
{
    push(2);
    push(12);
    push(9);
    push(17);
    push(13);
    push(10);
    push(16);
    push(14);
    push(114);
    display(head);
    quickSort(&head);
    printf("\n");
    display(head);

    system("pause");
    return 0;
}
void push(int key)
{
    link newnode;
    newnode= (link)malloc(sizeof(node));
    newnode->data=key;
    newnode->next=head;
    head=newnode;
}
void display(link  head)
{
    link ptr=head;
    while(ptr!=NULL)
    {
        printf("%4d",ptr->data);
        ptr=ptr->next;
    }
    
}
link FindTail(link head)
{
    link ptr=head;
    while(ptr->next!=NULL)
        ptr=ptr->next;
    return ptr;
}
link partition(link head, link end,link* newHead,link* newEnd)
{
    link pivot = end;
    link prev = NULL, cur = head, tail = pivot;
 
    // During partition, both the head and end of the list
    // might change which is updated in the newHead and
    // newEnd variables
    while (cur != pivot) {
        if (cur->data < pivot->data) {
            // First node that has a value less than the
            // pivot - becomes the new head
            if ((*newHead) == NULL)
                (*newHead) = cur;
 
            prev = cur;
            cur = cur->next;
        }
        else // If cur node is greater than pivot
        {
            // Move cur node to next of tail, and change
            // tail
            if (prev)
                prev->next = cur->next;
            link tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
 
    // If the pivot data is the smallest element in the
    // current list, pivot becomes the head
    if ((*newHead) == NULL)
        (*newHead) = pivot;
 
    // Update newEnd to the current last node
    (*newEnd) = tail;
 
    // Return the pivot node
    return pivot;
}
/*
link Partition(link first ,link last,link * newfirst_ref,link * newlast_ref)
{
    //Get first node of given linked list
	link pivot = first;
	link front = first;
	int temp = 0;
	while (front != NULL && front != last)
	{
		if (front->data < last->data)               //比pilot小在左邊，大的在右邊
		{
			pivot = first;                           //pivot實際是last ,最後first跟last會交換
			//Swap node value
			temp = first->data;
			first->data = front->data;
			front->data = temp;
            if ((*newfirst_ref) == NULL)
                (*newfirst_ref) = first;
			//Visit to next node                    //front first同時到下一node代表比pilot小 
			first = first->next;                  // 只有front移動，代表first是比pivot大 下次交換要把first移到右邊
		}
		//Visit to next node
		front = front->next;
	}
	//Change last node value to current node
	temp = first->data;                     //first左邊都比pivot小，把last first做交換
	first->data = last->data;
	last->data = temp;

    if ((*newfirst_ref) == NULL)
        (*newfirst_ref) = pivot;
    (* newlast_ref) = last;
    printf("\n");
    display(head);
	return pivot;
}
*/
link quickSortRecur(link head,link end)
{
    // base condition
    if (!head || head == end)
        return head;
 
    link newHead = NULL, newEnd = NULL;
 
    // Partition the list, newHead and newEnd will be
    // updated by the partition function
    link pivot = partition(head, end, &newHead, &newEnd);
 
    // If pivot is the smallest element - no need to recur
    // for the left part.
    if (newHead != pivot) {
        // Set the node before the pivot node as NULL
        link tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
 

        // Recur for the list before pivot
        newHead = quickSortRecur(newHead, tmp);
 
        // Change next of last node of the left half to
        // pivot
        tmp = FindTail(newHead);
        tmp->next = pivot;
    }
 
    // Recur for the list after the pivot element
    pivot->next = quickSortRecur(pivot->next, newEnd);

    return newHead;
}
void quickSort(link * headRef)
{
    (*headRef)= quickSortRecur(*headRef, FindTail(*headRef));
    return;
}