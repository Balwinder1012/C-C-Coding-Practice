#include<stdio.h>
#include<conio.h>

void sum(int a,int b){

    int l = printf("%*s%*s",a,"",b,"");
    printf("%d",l);
}

int main(){

    int a,b;

    scanf("%d",&a);
    scanf("%d",&b);
    sum(a,b);
    return 0;

}
