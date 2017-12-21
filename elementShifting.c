#include<stdio.h>
#include<conio.h>
#include<malloc.h>

void printArray(int a[],int n){

    for(int i=0;i<n;i++)
        printf("%d ",a[i]);

}
int main(){

  int *a;
    int n,i,pos=n-1,k;
    scanf("%d",&n);
    a = (int *)malloc(sizeof(int)*n);
    for(i=0; i<n;i++)
       scanf("%d",&a[i]);

    pos=n-1;
    for(i=n-1;i>=0;i--){

        if(a[i]<0){

            int temp = a[i];

            for(k=i;k<pos;k++)
                a[k] = a[k+1];

            a[pos] = temp;

            pos--;

        }





    }




    printArray(a,n);






    return 0;

}
