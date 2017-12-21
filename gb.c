#include<stdio.h>
#include<conio.h>
//#include<alloc.h>
static int stack[100];
int top=-1;

void push_(int elem){

    stack[++top]=elem;
}

void display_(){

    for(int i=top;i>=0;i++)
        printf("%d ",stack[i]);
}

void solve_(int a[],int n){
        printf("\nhelo");

    for(int i=0;i<n-1;i++){
        a[i]+=a[i+1];
        push_(a[i]);
    }
    solve_(a,n-1);
    display_();

}

int main(){
    int a[] = {3,4,7,5,3,2,4};
    int n = 7;
    solve_(a,n);
   // printf("top = %d",top);
}
