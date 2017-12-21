#include<bits/stdc++.h>
using namespace std;

int lChild(int i){

    return (i+1)*2 -1;

}
int rChild(int i){
    return (i+1)*2;
}
void swap_(int a[],int i,int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;


}
void heapify(int a[],int i,int n){
   // cout<<"$";
    int largest = i;
    int l = lChild(i);
    int r = rChild(i);

    if(l>=n || r>= n ){
        return;
    }
    if(a[l] > a[i]){
        if(a[r] > a[l]){
            largest = r;
        }
        else{
            largest = l;
        }

    }
    else{
        if(a[i]<a[r])
            largest = r;
    }
    if(largest!=i){
        swap_(a,i,largest);
        heapify(a,largest,n);
    }


}
void buildHeapify(int a[],int n){

    for(int i=n/2-1;i>=0;i--){

        heapify(a,i,n);

    }


}

int maxElement(int a[],int n){
    return a[0];
}

int extractMax(int a[],int *n){

    int temp = a[0];
    swap_(a,0,*n-1);
    heapify(a,0,*n-1);
    *n = *n-1;
    return temp;

}
int main(){
    int a[] = {33,2,34,51,23,45,6};
    int n = sizeof(a)/sizeof(int);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    buildHeapify(a,n);
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;

    cout<<maxElement(a,n);
    cout<<extractMax(a,&n);

cout<<endl;
 for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
