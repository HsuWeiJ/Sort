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
void quick(int*, int, int);
void dataout(int*);
void swap(int*, int, int);
int main(void)
{
    int i;
    int data[SIZE]={8,7,6,5,4,3,2,1};

    printf("原先陣列:\n");
    dataout(data);

    quick(data, 0, SIZE - 1);

    printf("排序陣列:\n");
    dataout(data);
    system("pause");
    return 0;
}

void quick(int *data,int left,int right)
{
    int size=right-left+1;
    if(left<right)
    {
        int i=left;
        int j=right+1;
        while(1)
        {
            while(  (i+1<SIZE)&&(data[++i]<data[left]) );   //往右尋找比pilot值大的
            while(  (j-1>-1)&&(data[--j]>data[left]) );  //往左尋找比pilot值小的
            if(i>=j)
                break;                          //代表i,j已經交會 右邊都比pilot大,左邊都比pilot小
            swap(data,i,j);                     //將在數列左邊比較大的值跟數列右邊比較小的值交換
        }
        swap(data,left,j);
        quick(data,left,j-1);
        quick(data,j+1,right);
        
    }
}

void dataout(int* data)
{
    for (int i = 0; i < SIZE; i++)
        printf("%3d", data[i]);
    printf("\n");
}
void swap(int* data, int i, int j)
{
    int tem = data[i];
    data[i] = data[j];
    data[j] = tem;
}
