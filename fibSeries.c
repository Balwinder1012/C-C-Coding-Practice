#include<stdio.h>
#include<conio.h>
#include<malloc.h>
int fib(int num,int *ptr){

    if(num==1) return 1;
    else if(num<=0) return 0;

    else if(ptr[num]==0){


        ptr[num] =  fib(num-1,ptr) + fib(num-2,ptr);

    }
    else
        return ptr[num];



}
int main(){
// 0 1 1 2 3 5
    int n;
    int num;
    int *ptr;
    printf("Enter the number\n");

    scanf("%d",&n);
    ptr = (int*)malloc(sizeof(int)*(num+1));
    //num = fib(n);
    printf("%d",fib(n,ptr));
    return 0;

}
