#include<stdio.h>
#include<conio.h>

long sum(long int a[],int left,int right){

    if(left==right)
        return a[left];


        return a[left] + sum(a,left+1,right);



}
int main(){

    long int a[] = {1,5,4,5,3,6,8};

    printf("%ld",sum(a,0,6));





}
