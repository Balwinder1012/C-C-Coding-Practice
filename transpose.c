#include<stdio.h>
#include<malloc.h>
int main(){

    int *a;
    int m=4;
    int n=3;
    int i,j;
    int counter=0;
    a = (int *)malloc(m*n*sizeof(int));

    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            a[i][j] =counter++;

    for(i=0;i<m;i++)
        for(j=0;j<n;j++)

        printf("%d ",a[i][j]);


}
