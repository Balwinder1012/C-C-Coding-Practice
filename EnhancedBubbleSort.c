#include<stdio.h>
#include<conio.h>
int stack[6];
int top = -1;
void push(int elem){

    stack[++top] = elem;
}

int pop(){
    return (stack[top--]);
}

void swap(int *p,int *q){

    int temp = *p;
    *p = *q;
    *q = temp;

}

void sortArray(int a[],int n){

    int i,j,val;
    for(i=0;i<n-1;i++){
        if(top<0)
            push(0);

        val = pop();

        for(j=val;j<n-i-1;j++){
            if(a[j]> a[j+1])
                swap(&a[j],&a[j+1]);
            else
                push(j);


        }

    }



}

void printArray(int a[],int n){

    int i;
    for(i=0;i<n;i++)
        printf("%d ",a[i]);


}
int main(){

    int a[] = {5,1,4,2,8};
    int n=5;

    printArray(a,n);
    printf("\n");

    sortArray(a,n);
    printArray(a,n);



}
