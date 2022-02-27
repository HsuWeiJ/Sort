// C Program
// Quicksort on singly linked list

#include <stdio.h>
 //for malloc function
#include <stdlib.h>

//Create structure
struct Node
{
	int data;
	struct Node *next;
};
struct Node *head = NULL;
//Add new node at end of linked list 
void insert(struct Node **head, int value)
{
	//Create dynamic node
	struct Node *node = (struct Node *) malloc(sizeof(struct Node));
	if (node == NULL)
	{
		printf("Memory overflow\n");
	}
	else
	{
		node->data = value;
		node->next = NULL;
		if ( *head == NULL)
		{
			*head = node;
		}
		else
		{
			struct Node *temp = *head;
			//find last node
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			//add node at last possition
			temp->next = node;
		}
	}
}
//Display linked list element
void display(struct Node *head)
{
	if (head == NULL)
	{
		printf("Empty linked list");
		return;
	}
	struct Node *temp = head;
	printf("\n Linked List :");
	while (temp != NULL)
	{
		printf("  %d", temp->data);
		temp = temp->next;
	}
}
//Find last node of linked list
struct Node *last_node(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL && temp->next != NULL)
	{
		temp = temp->next;
	}
	return temp;
}
//Set of given last node position to its proper position
struct Node *partition(struct Node *first, struct Node *last)
{
	//Get first node of given linked list
	struct Node *pivot = first;
	struct Node *front = first;
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
	return pivot;
}
//Perform quick sort in given linked list
void quick_sort(struct Node *first, struct Node *last)
{
	if (first == last)
	{
		return;
	}
	struct Node *pivot = partition(first, last);
	display(head);

	if (pivot != NULL && pivot->next != NULL)
	{
		quick_sort(pivot->next, last);
	}
	
	if (pivot != NULL && first != pivot)
	{
		quick_sort(first, pivot);
	}
}
int main()
{
	
	//Create linked list
	insert( &head, 41);
	insert( &head, 5);
	insert( &head, 7);
	insert( &head, 22);
	insert( &head, 28);
	insert( &head, 63);
	insert( &head, 4);
	insert( &head, 8);
	insert( &head, 2);
	insert( &head, 11);
	
	/*insert( &head, 3);
	insert( &head, 2);
	insert( &head, 1);
	*/
	printf("\n Before Sort ");
	display(head);
	quick_sort(head, last_node(head));
	printf("\n After Sort ");
	display(head);
    system("pause");
	return 0;
}
