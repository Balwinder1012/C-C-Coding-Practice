#include<stdio.h>
#include<conio.h>

int findMin(int a[]){

    int min = 1000;
    for(int i=0;i<6;i++)
        if(min>a[i] && a[i]!=0)
            min = a[i];

    return min;
}

int areElementsZero(int a[]){

    int flag = 1;
    for(int i=0;i<6;i++)
        if(a[i]!=0){
            flag = 0;
            break;

        }
    return flag;
}

void main()
{

    int a[] = {4,0,1,0,5,6};

    for(int i=0; i<6; i++)
        printf("%d ",a[i]);


    printf("\n");

    while(!areElementsZero(a))
    {
        int min = findMin(a);

        for(int i=0; i<6; i++)
            if(a[i]!=0)
                a[i]-=min;

    }

    for(int i=0; i<6; i++)
      printf("%d ",a[i]);



}
