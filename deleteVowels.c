#include<stdio.h>
int checkVowels(char ch){
    if(ch=='a' || ch=='e' ||ch=='i' ||ch=='o' ||ch=='u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' )
        return 1;
    return 0;

}
void removeVowels(char ch[]){

    int i=0,j;
    while(ch[i++]!='\0')
        if(checkVowels(ch[i])){
                for(j=i;ch[j]!='\0';j++)
                    ch[j] = ch[j+1];
        i--;
        }
}
int main(){

    char ch[80];
    gets(ch);
    removeVowels(ch);
    puts(ch);
}
