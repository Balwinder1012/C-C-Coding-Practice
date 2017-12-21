#include<stdlib.h>
int key(int n,int exp){
    printf("#%d#",(n/exp)%10);
    return (n/exp)%10;

}
void countingSort(int a[],int n,int exp){

    int sum[10]={0};
    int output[n];
    for(int i=0;i<n;i++){
        sum[key(a[i],exp)]++;
    }
    for(int i=1;i<10;i++){

        sum[i] += sum[i-1];

    }
   // printArray(sum,10);
 //   printf("###");
    for(int i=n-1;i>=0;i--){
  sum[key(a[i],exp)]--;
        output[sum[key(a[i],exp)]] = a[i];


    }

    for(int i=0;i<n;i++){
        a[i] = output[i];
    }

 printArray(a,n);


}
int findMax(int a[],int n){

    int max=a[0];
    for(int i=1;i<n;i++)
    if(max<a[i]){
        max=a[i];
    }

    return max;

}
void radixSort(int a[],int n){

    int max = findMax(a,n);

    for(int i=1;i<max;i*=10){
        countingSort(a,n,i);
      //  printf("$");
    }





}

void printArray(int a[],int n){
    printf("\n\n");
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }


}
int main(){
    int a[]={23,45,21,78,2,56},n;
    //int a[]={3,1,3,0,3},n;

    n = sizeof(a)/sizeof(int);
printArray(a,n);

    radixSort(a,n);
    printArray(a,n);

}
