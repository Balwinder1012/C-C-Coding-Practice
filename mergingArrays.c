#include<stdio.h>
#include<malloc.h>

void mergeSortedArray(int a[],int b[],int n,int m){


    printf("\n#########################\n");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);

    printf("\n#########################\n");
     for(int i=0;i<m;i++)
        printf("%d ",b[i]);
    printf("\n#########################\n");
    int i=0,j=0,k;

 //   for(k=0;k<(1);k++){

		if(a[i] > b[0]){

			for(int l=i;l<n;l++)
			    a[l+1] = a[l];
			a[i] = b[0];
            n++;

            for(int u=0;u<n+1;u++)
                printf("\%d ",a[u]);
   //     }
	//	i++;
}
}

int main(){
	int a[20],b[10];
	int n=5,m=3;

//	printf("%d",0%4);

    	scanf("%d",&n);
	for(int i=0;i<n;i++){
	  scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for(int j=0;j<m;j++){
	 scanf("%d",&b[j]);
	}

	//mergeSortedArray(a,b,n,m);

	for(int i=0;i<n;i++)
        printf("%d ",a[i]);
printf("\n\n\n");



//mergeSortedArray(a,b,n,m);
}
