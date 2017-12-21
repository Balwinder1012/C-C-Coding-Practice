void rotateAgain(char ch[], int l,int count){
    int i;
    char temp;
    if(l>=count){
        temp = ch[l-1];
        puts(ch);

        for(i=l-1;i>0;i--)
            ch[i] = ch[i-1];

        ch[0]  = temp;
        rotateAgain(ch,l,count+1);
    }

}
int main(){

    char ch[100];
    gets(ch);
    rotateAgain(ch,strlen(ch),1);

}

