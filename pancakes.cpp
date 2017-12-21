#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int isDone(char ch[]){
    int i=0;
    while(ch[i]!='\0'){
        if(ch[i]=='-')
            return 0;
        i++;
    }
    return 1;
}


void flip(char ch[],int p,int k){


    for(int i=p;i<k;i++){
        ch[i] = ch[i]=='+' ? '-' : '+';
    }
}
void solveIt(char s[],int k){
    queue<int> q;
    int c=0;
    int n = strlen(s);
    q.push(0);
    if(isDone(s)){
        printf("0");
        return;
    }
    while(!q.empty()){
        int p = q.front();
        q.pop();
         if(isDone(s)){
       printf("%d",c++);
        return;
    }
        for(int i=p;i<=n-k;i++){
                 if(isDone(s)){
        printf("%d",c++);
        return;
    }
            flip(s,i,k);
            printf("\n%d %s",c,s);
            q.push(i+1);
        }




    }

}
int main(){

    char ch[50];
    int k;
    scanf("%s",ch);
    scanf("%d",&k);

    solveIt(ch,k);


}
