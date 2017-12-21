#include<stdio.h>
#define null '\0'

int foundLimiters(char ch,char limiters[],int n);
int numberOfWords(char *ch,char *limiters){

    int i=0,counter=0;
    int n = strlen(limiters);
    while(ch[i]!=null)
    {

        while(foundLimiters(ch[i],limiters,n) && ch[i]!=null)          // ignore the limiters at the starting
            i++;

        if(!foundLimiters(ch[i],limiters,n) && ch[i]!=null)
            counter++;


        while(!foundLimiters(ch[i],limiters,n)&& ch[i]!=null)           //traverse the word
            i++;

    }
    return counter;

}
int foundLimiters(char ch,char limiters[],int n){

   for(int i=0;i<n;i++)
        if(ch==limiters[i])
            return 1;


    return 0;

}
int main(){

    char ch[100],limiters[20];
    printf("Enter the String\n");
    gets(ch);


    printf("Enter the delimiters\n");
    gets(limiters);

    printf("%d",numberOfWords(ch,limiters));
}








