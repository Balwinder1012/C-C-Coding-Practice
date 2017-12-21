#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <malloc.h>

int main() {

    int x;
    int *ptr;
    int *ptr2;
    int *temp;
    int *sorting;
    scanf("%d",&x);

    ptr = (int *)malloc(sizeof(int)*x);
    ptr2 = (int *)malloc(sizeof(int)*10);
    sorting = (int *)malloc(sizeof(int)*x);
    temp = ptr;
    for(int i=0;i<x;i++){


        scanf("%d",temp++);


    }
    temp = ptr;

    for(int i=0;i<10;i++){
        ptr2[i]=0;
    }
    for(int i=0;i<10;i++){

        ptr2[ptr[i]]++;

    }




    for(int i=1;i<10;i++){

        ptr2[i]+=ptr2[i-1];

    }


    for(int i=0;i<x;i++){


       sorting[ptr2[ptr[i]]-1] = ptr[i];


          ptr2[i]--;




    }




    for(int i=0;i<x;i++)
        printf("%d ",sorting[i]);

    return 0;
}
