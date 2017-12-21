#include<stdio.h>
#include<conio.h>
#include<string.h>

int main(){

    char word[56];
    static int letters[26];
    int i,j,counter=0;
    int n;
    printf("Enter Word\n");
    scanf("%s",word);



    n = strlen(word);


    for(i=0;i<n;i++)
        letters[word[i] - 'a']++;


    printf("\n");
    for(i=0;i<26;i++){
        if(letters[i]>0){
            counter++;
        }
    }
    printf("\n no of distinct - %d",counter);


    return 0;



}
