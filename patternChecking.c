#include<stdio.h>
#include<conio.h>
char *checkingPattern(char input[],char pat[]){

    char *start,*p1,*p2;
    //printf("Heuy");
    for(start = &input[0]; *start != '\0';start++){

        p1 = pat;
        p2 = start;

        while(*p1!='\0'){

            if(*p1 != *p2)
                break;

            p1++;
            p2++;

        }
        if(*p1=='\0'){
          printf("....%c.....",*start);  return start;
        }
    }
    printf("Sending null");
    return NULL;


    }





int main(){


    char ch[] = {'H','e','l','l','o','H','i','i','\0'};
    char pattern[] = {'H','i','i','\0'};
    char *c;
    c=checkingPattern(ch,pattern);
    if(c)
    printf("Null\n");
    else
        printf("Getting something %c",*c);
}

