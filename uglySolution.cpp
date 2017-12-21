#include<iostream>
using namespace std;
int pow(int p,int n){
    if(n==0) return 1;
    if(n==1) return p;
    return p * pow(p,n-1);

}
void  checking_(int *num,int p){

    int i=1;
    while((*num)%pow(p,i)==0)
        i++;


    i--;
    *num = (*num)/pow(p,i);
}
int isDirty(int num){

    checking_(&num,2);
    checking_(&num,3);
    checking_(&num,5);

    return num;


}
void printDirty(int n){

    int dirtyCount=1;
    int num,dirty=num=1;
    int n1=n;
    while(dirtyCount!=n){
        num++;
        if(isDirty(num)==1){
            dirtyCount++;
            dirty = num;
        }


    }
    cout<<dirty;


}
int main(){
    int n;
    cin>>n;
    printDirty(n);

}
