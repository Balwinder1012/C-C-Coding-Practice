#include<malloc.h>
#include<stdio.h>
char *abbTheName(char ch[],int i,int index,int first){

    static char *name;


    if(first){
        name = (char *)malloc(sizeof(char)*100);
        first=0;

    }

    if(notLastWord(ch,i)){

    while(ch[i]==' ' && ch[i]!='\0')
        i++;

    name[index++]=ch[i];

    name[index++]='.';
    name[index++]=' ';
    while(ch[i]!=' '&&ch[i]!='\0')
      i++;

    return abbTheName(ch,i,index,first);

    }

    while(ch[i]==' ')
        i++;

    while(ch[i]!=' ' && ch[i]!='\0')
        name[index++] = ch[i++];

    name[index] = '\0';

    return name;
}

int notLastWord(char ch[],int i){

    while(ch[i]==' ' && ch[i]!='\0')
        i++;

    while(ch[i]!=' '){
        if(ch[i++]=='\0')
            return 0;

    }

    while(ch[i++]==' ')
        if(ch[i++]=='\0')
            return 0;



     return 1;




}
int main(){
    char ch[50];
    int n;

    printf("Enter the no. of names\n");
    scanf("%d",&n);
    fflush(stdin);
    while(n-->0){
     gets(ch);
     puts(abbTheName(ch,0,0,1));
   }


}
