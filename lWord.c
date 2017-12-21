//Largest word

#define null '\0'

int validAlphaNum(char c){

    if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9') || c==' ')
        return 1;
    return 0;

}
void removeSpecialChars(char ch[]){

    int i=0,j,flag;
    while(ch[i]!=null){

        flag = 1;

        if(!validAlphaNum(ch[i])){
                        for(j=i;ch[j]!=null;j++){

                ch[j] = ch[j+1];
            }
            flag = 0;
        }

        if(flag)
          i++;
    }



}

int theWord(char s[]){

    int i=0,j,l=0;
    int index1=0,index2=0;
    //int
    while(s[i]!=null){

        while(s[i]!=null && s[i]==' ' ) i++;


        j=i;


        while(s[j]!=null && s[j]!=' ') j++;



        if(l<j-i-1){
            l = j-i-1;
            index1=i;
            index2=j;
        }


        i=j;

        if(s[i]==null) break;

        i++;

    }
    for(int i=index1;i<=index2;i++)
        printf("%c",s[i]);


}


int main(){

    char ch[100];
    gets(ch);

    removeSpecialChars(ch);

    theWord(ch);

}
