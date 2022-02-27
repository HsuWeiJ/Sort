#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SIZE 8
/*--------------------
Structure
--------------------*/
/*--------------------
Global Variable
--------------------*/
/*--------------------
Function 
--------------------*/
void MergeSort(int *data,int front,int end);
void Merge(int *data,int front,int end);
int main(void)
{
    int i;
    int data[SIZE]={2,4,3,5,1,6,8,7};
    MergeSort(data,0,SIZE-1);
    for (int i = 0; i < SIZE; i++)
        printf("%d", data[i]);
    system("pause");
    return 0;
}
void MergeSort(int *data,int front,int end)
{
    int mid= (front+end)/2;
    if(front<end)
    {
        MergeSort(data ,front ,mid);
        MergeSort(data ,mid+1 ,end);
        Merge(data , front,end);
    }
}
void Merge(int *data,int front,int end)
{
    int i;
    int mid = (front+end)/2;
    int LeftSubSize=mid-front+1;
    int RighttSubSize=end-mid;
    int *LeftSub=(int*)malloc(LeftSubSize*sizeof(int));
    int *RightSub=(int*)malloc(RighttSubSize*sizeof(int));
    int LeftIndex=0,RightIndex=0;
    for(i=0;i<LeftSubSize;i++)  
        LeftSub[i]=data[front+i];
    for(i=0;i<RighttSubSize;i++)  
        RightSub[i]=data[mid+1+i];   
    
    for(i=front;i<=end;i++)
    {
        if(LeftIndex>=LeftSubSize)
            data[i]=RightSub[RightIndex++];
        else if(RightIndex>=RighttSubSize)
            data[i]=LeftSub[LeftIndex++];
        else if(LeftSub[LeftIndex]<RightSub[RightIndex])
            data[i]=LeftSub[LeftIndex++];
        else if(LeftSub[LeftIndex]>=RightSub[RightIndex])
            data[i]=RightSub[RightIndex++];
    }
    
}