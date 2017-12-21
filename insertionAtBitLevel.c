#include<stdio.h>

int main(){

    int m = 215;
    int n = 15;

    for(int i=3;i<=6;i++)
        m &= (~(1<<i));

    n= (n<<3);
/*
    int left = ~0;
    left = left<<7;
    printf("%d\n",left);
    int right = (1<<3) - 1;
     printf("%d\n",right);
     m = m & (left|right);
     n = n << 3;
    m = m | n;*/
    printf("%d",m|n);

}
