#include<stdio.h>

void printOcc(char *ch){

    static int symbols[256],i;

    while(ch[i]!='\0')
       symbols[ch[i++]]++;


    for(i=0;i<256;i++)
        if(symbols[i]>0)
            printf("Symbol- %c Times- %d\n",i,symbols[i]);


}

int main(){

    char ch[200];
    gets(ch);
    printOcc(ch);

}
