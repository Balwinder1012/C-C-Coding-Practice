#include<bits/stdc++.h>
using namespace std;

int findIfEven(int a[],int n,int i,int p,int sum){

    if(p==0){

        return !(a[i-1]%2);
    }
    if(n==i){
        cout<<"Error";

    }


    a[i]=sum+1;
    sum = 2*sum + 1;
    return findIfEven(a,n,i+1,p-1,sum);


}
int main(){

    int a[20] = {2,3,4,1};
    int p=2;
    int sum=0;
    for(int i=0;i<4;i++){
        sum+=a[i];
    }
    if(findIfEven(a,sizeof(a)/sizeof(int),4,p,sum)){
        printf("\nEven\n");
    }
    else
        printf("\nOdd\n");

}
