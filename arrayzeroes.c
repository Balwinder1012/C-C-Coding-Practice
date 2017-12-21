#include<stdio.h>

int  main(){

    int a[][4]={{0,1,2,6},{3,0,3,1},{1,3,5,2},{2,4,0,1}};
    int m=4;
    int n=4;
    int i,j;
    int row[m];
    int col[n];
    int counter=0;

    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            if(a[i][j]==0){
                    row[counter]=i;
                    col[counter]=j;
                    counter++;
    }

    for(i=0;i<counter;i++)
        for(j=0;j<n;j++)
            a[row[i]][j]=0;

for(i=0;i<counter;i++)
        for(j=0;j<m;j++)
            a[j][col[i]]=0;

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",a[i][j]);
        printf("\n");
    }

    return 0;

}
