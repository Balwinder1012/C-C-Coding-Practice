#include<stdio.h>

char* subString(char ch[],int i,int j){
    char *sub;
    int index=0,len,size,k;
    len = strlen(ch);

    if(j<=len && i>=0 ){
    size = j-i;
    sub = (char *)malloc(sizeof(char)*size);

    for(k=i;k<j;k++)
        sub[index++] = ch[k];
    sub[index]='\0';
    }
    else
        sub="Enter valid indices for i and j";

    return sub;


}
int main(){
    char ch[200],*sub;
    int i,j;
    printf("Enter the String\n");
    gets(ch);
    fflush(stdin);

    printf("Enter two indices\n");
    scanf("%d%d",&i,&j);
    sub = subString(ch,i,j);
    puts(sub);
}
