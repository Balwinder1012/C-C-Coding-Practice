int counttheThe(char* ch,char* word,int f,int counter){

    int ending=-1;

    if(ch[f]!='\0'){


    while(ch[f]==' ' && ch[f]!='\0')
        f++;

    ending=f;
    while(ch[ending]!=' '  && ch[ending]!='\0' )
        ending++;

    if( caughtWord(ch,word,f))
        counter++;

    f=ending+1;


      return counttheThe(ch,word,f,counter);
    }
    return counter;

}

int caughtWord(char* ch,char* word,int f){

    int i=0;
    while(ch[f]!='\0' && ch[f]!=' ' && word[i]!='\0')
      if(word[i++]!=ch[f++])
            return 0;


    return 1;

}

int main(){
    char ch[200],word[20];
    gets(ch);
    gets(word);

    printf("%d",counttheThe(ch,word,0,0));
}


