#include<bits/stdc++.h>
#include<string.h>
using namespace std;
void solveItKmp(char text[],char pat[]){
    int n = strlen(pat);
    int m = strlen(text);

    int arr[n];
    arr[0]=0;
    int j=0;
    int i=1;
    int f=1;
    while(i<n){

        if(pat[i]==pat[j]){
                cout<<"$";
            arr[i]=j+1;
            i++;
            j++;
            f=0;
            continue;
        }
        else if(j!=0){
                    j=arr[j-1];
            continue;

        }
        else{
            arr[i]=0;
        }

        i++;

    }
    cout<<m;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
     j=0;
    i=0;
   while(i<m){

      //  cout<<i<<j<<endl;
        if(j>=1 && text[i]!=pat[j]){
            j = arr[j-1];
            continue;
        }

        else if(text[i]==pat[j]){
            j++;
            i++;
 if(j==n){
 cout<<"Match at "<<i-j<<endl;
            j=0; continue;

        }
        }

        if(j<1){
          //      cout<<"#";
            i++;
        }
      //  cout<<"$";
    }
}
int main(){

    char text[] = "ddabbbbbdfdjfgskuegfkugekugregfugejgfrddabdabdd";
    char pat[] = "ddab";
    solveItKmp(text,pat);

}
