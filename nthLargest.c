#include<limits.h>
#include<stdio.h>
int notFound(int elem,int excep[],int e){
    for(int i=0;i<e;i++)
        if(excep[i]==elem)
            return 0;

    return 1;

}
int largest(int a[],int n,int excep[],int e){

    int max = INT_MIN;
    for(int i=0;i<n;i++){
        if(notFound(a[i],excep,e) && a[i] > max){
            max = a[i];
        }
    }
    return max;

}
int findNthLargest(int a[],int n,int excep[],int e,int t){

    if(t==1)
        return largest(a,n,excep,e);
    excep[e++] = largest(a,n,excep,e);
    findNthLargest(a,n,excep,e,t-1);


}
int main(){

    int a[100],n,t;
    int exceptions[100],e=0;
    int ans;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("enter value of n ");
    scanf("%d",&t);
    if(t>n)
        printf("Wrong value of n");
    else{
            ans = findNthLargest(a,n,exceptions,e,t);
            if(ans==INT_MIN)
                printf("does not exist");
            else
                printf("%d",ans);
    }


}
