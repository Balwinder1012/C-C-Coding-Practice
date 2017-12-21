int square(int i){
    return i*i;
}
int main(){

    char ch[200];
    int a[200];
    int ai=0;
    int i=0;
    gets(ch);
    while(ch[i]!='\0'){

        if(ch[i]>='0' && ch[i]<='9')
            a[ai++]=ch[i]-'0';


        i++;
    }
   // printf("hi %d\n",ai);
    for(int i=0;i<ai;i++)
        printf("%d ",square(a[i]));



}

