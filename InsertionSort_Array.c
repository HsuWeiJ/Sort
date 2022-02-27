#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define SIZE 8
/*--------------------
Global Variable
--------------------*/
/*--------------------
Structure
--------------------*/
/*--------------------
Function 
--------------------*/
void Insertion(int*,int);
int main(void)
{
    int i;
    int data[SIZE]={2,4,3,5,1,6,8,7};
    Insertion(data,SIZE);
    for(i=0;i<SIZE;i++)
    {
        printf("%2d",data[i]);
    }


    system("pause");
    return 0;
}

void Insertion(int *data ,int size)
{
    int i,j,tem;
    for(i=1;i<8;i++)
    {
        tem=data[i];
        j=i-1;
        while(j>=0 && tem<data[j])
        {
            data[j+1]=data[j];
            j--;
        }
        data[++j]=tem;
            
    }
}