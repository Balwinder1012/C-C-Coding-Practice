int isUnique(char *ch,int j,char c){

    while(ch[j]!='\0'){

        if(ch[j]==c)
            return 0;
        j++;

    }
    return 1;


}
int main(){

    char ch[200];
    gets(ch);

    int i=0;
    while(ch[i]!='\0'){

        int j=i+1;
        if(isUnique(ch,j,ch[i])){

            printf("%c",ch[i]);
        }

        i++;


    }


}
