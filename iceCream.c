#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>

int main() {

    int testCases,i,j,m,n;
    int *ptr;
    int *temp;
    scanf("%d",&testCases);

    while(testCases>0){

        scanf("%d",&m);
        scanf("%d",&n);
        ptr = (int *)malloc(sizeof(int)*n);
        temp = ptr;

        for(i=0;i<n;i++)
            scanf("%d",temp++);

        for(i=0;i<n;i++){

            for(j=i;j<n;j++)
                if((ptr[i]+ptr[j])==m && i!=j){
                    printf("%d %d",i+1,j+1);
                    if(testCases!=1)
                        printf("\n");
                    goto label;

            }



        }

        label:
        testCases--;

    }

    return 0;
}

