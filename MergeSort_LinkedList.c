#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*--------------------
Structure
--------------------*/
struct list
{
    int num;
    struct list* next;
};
typedef struct list node;
typedef node* link;
/*--------------------
Global Variable
--------------------*/
link head = NULL;
link sorted = NULL;
/*--------------------
Function
--------------------*/
void push(int key);
void printlist(link head);
void FrontBackSplit(link source, link* front_ref, link* back_ref);
void MergeSort(link* head_ref);
link Merge(link a, link b);

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

    MergeSort(&head);

    printf("Linked List after sorting:\n");
    printlist(head);
    system("pause");
    return 0;
}

void push(int key)
{
    link  newnode;
    newnode = (link)malloc(sizeof(node));
    newnode->num = key;
    newnode->next = head;
    head = newnode;
}
void printlist(link head)
{
    link ptr = head;
    while (ptr != NULL)
    {
        printf("%3d", ptr->num);
        ptr = ptr->next;
    }
}
void FrontBackSplit(link source, link* front_ref, link* back_ref)
{
    // 使用快慢指標來處理
    link slow, fast;
    slow = source;
    fast = source->next;
    // 關鍵，讓 fast 前進兩個節點，slow 前進一個節點
    // 當 slow 走到一半時，fast 肯定在最後，一前一後可以形成兩個長度相似的子 List
    while (fast->next != NULL)
    {
        fast = fast->next;
        if (fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front_ref = source;
    *back_ref = slow->next;
    slow->next = NULL;
}
void MergeSort(link* head_ref)
{
    link head = *head_ref;
    link a, b;
    // 如果節點只有一個或是沒有，那不用排序
    if ((head->next == NULL) || (head == NULL))
        return;
    // 將 List 拆解成兩個子 List： a & b (丟址進去)
    FrontBackSplit(head, &a, &b);
    // 對子 List 使用遞迴排序
    MergeSort(&a);
    MergeSort(&b);
    // 將子List合併
    *head_ref = Merge(a, b);
}
link Merge(link a, link b)
{
    link  result = NULL;
    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;
    else if (a->num <= b->num)
    {
        result = a;
        result->next = Merge(a->next, b);
    }
    else
    {
        result = b;
        result->next = Merge(a, b->next);
    }
    return result;
}
