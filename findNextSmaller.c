#include<stdio.h>
void setBit(int *p,int a){
    int n=*p;
    int q = 1<<a;
     n= q | n;
    *p=n;
}
int main(){
    int n=13948;

    int num = n;
    int a=0;
    int b=0;
    //while we have zeroes pass them
    while((n&1)==0 && n!=0){
        a++;
        n>>=1;
    }
    //while we have ones pass them;
    while((n&1)==1 && n!=0){
        b++;
        a++;
        n>>=1;
    }
    setBit(&num,a);
    num &= ~((1<<a)-1);
    num |= ((1<<(b-1)) - 1);
    printf("%d",num);

    a=b=0;
    n=num=10115;
    while((n&1) && n!=0){
        a++;
        n>>=1;
    }
    while(!(n&1) && n!=0){
        b++;
        n>>=1;
    }
    int p = a+b;
    num &= (~(1<<p));

    num &= (~((1<<p)-1));

    num |= (((1<<(a+1))-1 )<<(p-a-1));

    printf("\n%d",num);

}
