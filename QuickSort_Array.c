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

    printf("����}�C:\n");
    dataout(data);

    quick(data, 0, SIZE - 1);

    printf("�Ƨǰ}�C:\n");
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
            while(  (i+1<SIZE)&&(data[++i]<data[left]) );   //���k�M���pilot�Ȥj��
            while(  (j-1>-1)&&(data[--j]>data[left]) );  //�����M���pilot�Ȥp��
            if(i>=j)
                break;                          //�N��i,j�w�g��| �k�䳣��pilot�j,���䳣��pilot�p
            swap(data,i,j);                     //�N�b�ƦC�������j���ȸ�ƦC�k�����p���ȥ洫
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
