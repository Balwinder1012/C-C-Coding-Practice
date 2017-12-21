#include <bits/stdc++.h>
using namespace std;
void markMultiples(bool mark[],int index,int n){
    for(int i=index<<2;i<n;i=i+index){
        mark[i]=true;
    }
}
printArray(bool mark[],int n){

    if(n>=2)
        printf("2 ");
    //printf();
    for(int i=3;i<n;i+=2){
        if(mark[i]==false){
            printf("%d ",i);
        }
    }
}
void solveRec(bool mark[],int n,int index){

    if(index>=n){
        printArray(mark,n);
        return;
    }
    int i;
    for(i=index;i*i<=n;i++){
        if(mark[i]==false){
            markMultiples(mark,i,n);
            break;
        }
     //   printf("#");
    }
    solveRec(mark,n,i+1);


}
void solveIteratively(bool mark[],int n){

    for(int i=3;i*i<n*2;i+=2){

        if(mark[i/2]==false){
            for(int j=i*3;j<n*2;j+=2*i){
                mark[j/2]=true;

            }
        }
    }
    printf("2 ");
    for(int i=1;i<n;i++){
        if(mark[i]==false){
            cout<<i*2+1<<" ";
        }
    }
}
void printThePrimes(int n){

    bool mark[n/2];
    memset(mark,false,sizeof(mark));
    //solveRec(mark,n+1,2);
    solveIteratively(mark,n/2);

 }
 isPrime(int bit[],int x){

  if(0)  if(((*bit) & (1<<x))){
        printf("\n# %d is set \n",x);
    }
    else{
         printf("\n# %d is not set \n",x);
    }
    return !((bit[x/64]) & (1<<((x>>1)&31)));

}
void setBit(int bit[],int j){

    (bit[j/64])= (bit[j/64])| 1<<((j>>1)&31); //modulus using bit is only pssible for numbers which are some power of 2
    //printf("#%d#",*bit);
}
void printPrimes(int bit[],int n){

    for(int i=3;i<n;i=i+2)
        if(isPrime(bit,i))
            cout<<i<<" ";
      //      printf("\n%d",bit);
}
void bitwise(int n){

    int bit[n/64];
    //memsset(bit,0,sizeof(set));

    for(int i=3;i*i<n;i+=2){

        if(isPrime(bit,i)){

            for(int j=i*i;j<n;j=j+i*2){

                setBit(bit,j);
            }
        }
    }
    cout<<2<<" ";
    printPrimes(bit,n);


}
int main(){

    int n;
    scanf("%d",&n);

   // printThePrimes(n);
   bitwise(n);
 }
