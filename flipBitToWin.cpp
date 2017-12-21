
#include<iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> getAlternatingSequence(int n){

    vector<int> seq;
    int searchingFor=0;
    int counter=0;
    while(n){
        if((n & 1) != searchingFor){
            seq.push_back(counter);
            searchingFor = n & 1;
            counter=0;

        }
        counter++;
        n  = n >> 1;


    }
    seq.push_back(counter);
    return seq;



}
void findLongestSequence(vector<int> &seq){

    int maxSeq=1;

     for(int i=0;i<seq.size();i=i+2){
        int zSeq = seq.at(i);
        int oneLeft = i-1 >=0 ? seq.at(i-1) : 0;
        int oneRight = i+1 < seq.size() ? seq.at(i+1):0;
        int thisSeq=0;
        if(zSeq==1){
            thisSeq = oneLeft + oneRight + 1;

        }
        else if(zSeq>1){
            thisSeq = 1 + max(oneLeft,oneRight);
        }
        else{
            thisSeq = max(oneLeft,oneRight);
        }

        maxSeq = max(thisSeq,maxSeq);

    }
    cout<<maxSeq;

}
void longestSequence(int n){

    vector<int> seq;
    seq = getAlternatingSequence(n);
   // cout<<"hello"<<endl;
    findLongestSequence(seq);


}

void longestSequence2(int n){

    int maxLength =1 ;
    int current = 0;
    int prev = 0;
    while(n){

        if((n&1)==1){
            current++;
        }
        else if((n&1)==0){

            prev = (n&2)==0 ? 0 : current;
           current = 0;

        }

        maxLength = max(prev + current + 1,maxLength);

        n = n>>1;


    }
    cout<<endl<<endl<<maxLength;

}
int main(){

    int n = 43;
    longestSequence2(n);


}
