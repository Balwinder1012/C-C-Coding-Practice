#include<stdio.h>
#include<conio.h>


void insertSort(long *a,int n){

    int i;
    int j;
    long key;
    for(i=1;i<n;i++){

        j=i-1;
        key = a[i];

        while(j>=0 && key < a[j]){
            a[j+1] = a[j];
            j--;


        }
        a[j+1]=key;


    }


}

int main(){

    long *ptr;
    long *temp;
    long n;
    printf("Enter the number of elements ");
    scanf("%ld",&n);
    printf("\nNo of elements entered %ld \n",n);
    ptr =  (long *)malloc(sizeof(long)*n);
    printf("Enter the elements\n");

    temp = ptr;

    for(int i=0;i<n;i++)
        scanf("%ld",temp++);



    for(int i=0;i<n;i++)
        printf("%ld ",ptr[i]);

    printf("\n");
    insertSort(ptr,n);

    for(int i=0;i<n;i++)
        printf("%ld ",ptr[i]);

    return 0;
}
