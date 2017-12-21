#include<stdio.h>

int main(){

    char ch[100];
    gets(ch);
    onlyUnique(ch);


}

void onlyUnique(char str[]){

    int i=0,j,f=0;
    char ch;
    //puts(str);
    while(str[i]!='\0'){
        f=0;
        ch = str[i];
        j=i+1;
        while(str[j]!='\0'){
            if(ch==str[j]){
                f=1;
                stringShift(str,j);

            }
            j++;
        }

         if(f)
            continue;
         i++;
        }

        // a a d a
        // a d a

puts(str);


}

void stringShift(char ch[],int j){


    while(ch[j]!='\0'){
        ch[j] = ch[j+1];
        j++;
    }
}
