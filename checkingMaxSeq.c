int main(){


    char ch[] = "DDDDDddAABCCAAADDDDDDDDDDDE";
    char prev='\0';
    char maxChar='\0';
    char maxCount=0;
    int count=0;

    for(int i=0;ch[i]!='\0';i++){

        char cur = ch[i];
        if(cur==prev){
            count++;
        }
        else
            count=1;
        if(count>maxCount){
            maxCount=count;
            maxChar = cur;
        }
        prev = cur;
    }
    printf("%c-%d",maxChar,maxCount);

}
