#include<stdio.h>
int main(){

    int t;
    scanf("%d",&t);
    while(t-->0){

        long long int n;
        scanf("%lld",&n);
        long long int r;
        int flag=1;
        scanf("%lld",&r);
        long long int *a = (int *)malloc(sizeof(long long int)*n);
        for(int i=0;i<n;i++){
            scanf("%lld",&a[i]);
        }
        long long int left = 0;
        long long int right = 1000000001;
        long long int prev = a[0];
        for(int i=1;i<n-1;i++){

            if(prev>r){

                if(a[i]<prev && a[i]>left){
                    right = prev ;
                  //  left = a[i];
                    prev = a[i];
                    //left =  prev = a[i];
                    continue;
                }
                else{
                    flag = 0;
                    break;
                }


            }
            else{


                if(a[i]> prev && a[i]<right){
                    left = prev;
                    prev = a[i];
                    continue;
                }
                else{
                    flag = 0;
                    break;
                }

            }




        }
        printf("%s\n",flag==1 ? "YES" : "NO");


    }


}
