#include<stdio.h>
#include<string.h>
int countWords(char ch[],int f,int count);

int count_(char ch[]){
int counter=0;
int i=0;
while(ch[i]!='\0'){

    while(ch[i++]==' ');

    while(ch[i]!=' ' && ch[i] != '\0')
        i++;

    counter++;


}
return counter;

}
int main(){

//Calculate the number of words
    char ch[500];
    gets(ch);
    printf("%d",count_(ch));
    //printf("%d",countWords(ch,0,0));




}

int countWords(char ch[],int f,int count){

    if(ch[f]=='\0')
        return count;

    while(ch[f]==' ' && ch[f]!='\0')
        f++;

  if(ch[f]!=' ' && ch[f]!='\0')
        count++;

    while(ch[f]!=' ' && ch[f]!='\0')
        f++;

    return countWords(ch,f,count);

}

