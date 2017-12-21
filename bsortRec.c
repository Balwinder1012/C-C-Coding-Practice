#include<stdio.h>
#include<conio.h>

int solve_(int a[5][5],int p.int q,int r,int c,int n,int sum){

    if(r+1 > p-1 && c+1 > q-1 && c-1 <0 && n==sum)
        return 1;

    if(r+1<=p-1 && c-1>=0)
        return solve_(a,p,q,r+1,c-1,n+a[r][c],sum);

    if(r+1<=p-1 && c+1<=q-1 )
        return solve_(a,p,q,r+1,c+1,n+a[r][c],sum);

    return 0;

}

int main(){

    int a[5][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    int sum=59;
    if(solve_(a,5,5,0,2,0,sum))
        printf("YES");
    else
        printf("NO");

        return 0;
}
