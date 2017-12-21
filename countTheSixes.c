#include<stdio.h>

int main(){


    int l;
    int r;
    scanf("%d",&l);
    scanf("%d",&r);

    int counter=0;
    for(int i=l;i<=r;i++){
        int n=i;

        while(n>0){

            int r = n%10;
            if(r==('6'-'0')){
                counter++;

            }
             n=n/10;


        }
    }
        printf("Number of 6s are %d",counter);





}
