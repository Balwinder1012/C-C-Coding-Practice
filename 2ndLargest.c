#include<stdio.h>

int main(){

    int l=0,s=0,i;
    int a[100],n;

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);

    }

printf("%d",findSL(a,n));

}

int findSL(int a[],int n){
    int l=0,s=0,i;
    for(i=0;i<n;i++){


        if(a[i]>1 && isPrime(a[i]) && a[i]>l){

                l=a[i];

        }

    }
//    printf("df%d \n",l);
    for(i=0;i<n;i++){


        if(a[i]>1 && isPrime(a[i]) && a[i]!=l && a[i]>s){



                s=a[i];//printf("%d  ",s);

        }

    }

 //   printf("\n%d",s);
    return s==l?-1:s;

}

int isPrime(int n){

    int i=2;

    for(;i<n/2;i++){
        if(n%i==0)
            return 0;

    }

    return 1;
}
