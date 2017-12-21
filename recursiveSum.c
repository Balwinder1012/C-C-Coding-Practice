#include<stdio.h>
int solve(int a[5][5],int m,int n,int p,int q,int c,int sum){

    if(p+1>=m+1&& c==sum){
        return 1;
    }
    else if(p+1<m && q-1>=0 && q+1<n)
       {
           return solve(a,m,n,p+1,q-1,c+a[p][q],sum) ||
                 solve(a,m,n,p+1,q+1,c+a[p][q],sum);
       }
    else if(p+1 <= m && q-1 >=0 )
        return solve(a,m,n,p+1,q-1,c+a[p][q],sum);

    else if(p+1<m+1 && q+1 <n)
        return solve(a,m,n,p+1,q+1,c+a[p][q],sum);

    else
        return 0;



}
/*int solve_(int a[5][5],int p,int q,int r,int c,int n,int sum){
int o,x;
    if(r+1 >=p-1  && n==sum)
        return 1;

    if(r+1<=p-1 && c-1>=0 && c+1<=q-1)
        {o=solve_(a,p,q,r+1,c-1,n+a[r][c],sum);
       // printf("    %d hello%d",c,r);
         x=solve_(a,p,q,r+1,c+1,n+a[r][c],sum);
         }
         else if(r+1<=p-1&& c-1>=0)
             solve_(a,p,q,r+1,c-1,n+a[r][c],sum);

    if(r+1<=p-1 && c+1<=q-1 )
        return solve_(a,p,q,r+1,c+1,n+a[r][c],sum);

    return 0;

}*/

int main(){

    int a[5][5] = {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
    int sum=46;
    if(solve(a,5,5,0,2,0,sum))
        printf("YES");
    else
        printf("NO");

        return 0;
}

