#include<stdio.h>
#include<conio.h>
#define size 500
void multiply(int x,int a[],int *s){

    int prod,i,carry=0;
    for(i=0;i<(*s);i++){

        prod = a[i]*x + carry;
        a[i] = prod % 10;
        carry = prod/10;


    }
    while(carry){

        a[*s] = carry % 10;
        carry /= 10;
        (*s)++;


    }


}
int main(){

    int a[size],i,n,fact;
    int s=1;

    //for(i=0;i<size;i++)
        a[0] = 1;

    printf("Enter the number\n");
    scanf("%d",&n);

    for(i=2;i<=n;i++){

           multiply(i,a,&s);

    }

   // printf("hello %d\n",s);
    for(i=s-1;i>=0;i--)
        printf("%d",a[i]);





}


