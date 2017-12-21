#include<stdio.h>
int main(){

    int t;
    scanf("%d",&t);
    while(t-->0){

        long int n;
        long long diamonds=0;
        scanf("%ld",&n);
       // long long int n1 = n*n;
        long long check=2;
        long long count=1;
        for(long int i=0;i<n;i++){
                check = i+2;
            for(long int j=0;j<n;j++){
                 diamonds += check%11;

             check++;



            }

        }

        printf("%lld",diamonds);

    }
}
