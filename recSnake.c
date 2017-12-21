#include<stdio.h>

int main(){

    int a[3][6] = {{1,2,3,4,5,6},{7,8,9,10,11,12},{13,14,15,16,17,18}};

    int m=3;
    int n=6;

    solve(a,0,0,m,n);

}

void solve(int a[6][6], int  i,int j,int m,int n){



        if(m==1||m==0&&n==0||n==1)
            return 0;
        else{
            for(int k=0;k<n;k++)
                printf("%d   ",a[i][k]);
            for(int l=i+1;l<m;l++)
                printf("%d ",a[l][m-1]);
            for(int w=n-2;w>=0;w--)
                printf("%d", a[m-1][w]);
            for(int b=m-1;b<i+1;b++)
                printf("%d",a[b][i]);
            solve(a,i+1,j+1,m-2,n-2);
        }


}
