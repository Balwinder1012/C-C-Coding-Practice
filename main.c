#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int Partition(int a[],int left,int right);
void quickSort(int a[],int left,int right,int first,int start)
{

    int Q;
    int index;
    if(left<right)
    {

        int Q = Partition(a,left,right);



        quickSort(a,left,Q-1,0,5);
        quickSort(a,Q+1,right,0,5);



    }


}
//Partition for last element
int Partition(int a[],int left,int right)
{

    int x=a[right];
    int i=left-1;
    int j;
    int temp;
    int index;
    for(j=left; j<right; j++)
    {


        if(a[j] <= x)
        {
            i++;
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;



        }





    }
    temp = a[i+1];
    a[i+1] = a[right];
    a[right]=temp;



    return i+1;


}



//partition for first element




int main()
{

    int n;
    int *ptr;
    int i;
    int *temp;

    scanf("%d",&n);

    ptr = (int *)malloc(sizeof(int)*n);
    temp = ptr;
    for(i=0; i<n; i++)
       scanf("%d",(temp++));



    temp = ptr;
    for(i=0; i<n; i++)
      printf("%d ",temp[i]);

    printf("\n");
    quickSort(ptr,0,n-1,0,n-1);


    printf("\n");
    temp = ptr;
    for(i=0; i<n; i++)
        printf("%d ",temp[i]);



return 0;
}
