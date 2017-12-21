#include<stdio.h>
int ifValidLetter(char ch);
void printPosition(char *ch)
{

    int i=0;
    int l=0;
    while(ch[i]!='\0'){
       if(!ifValidLetter(ch[i]))
          i++;
        else
           break;
    }

    printf("First Position : %d",i);
    l=i;
    while(ch[l]!='\0')
      l++;

    l--;

    while(l-->=0)
        if(ifValidLetter(ch[l]))
        {
            printf("\nSecond Position : %d",l);
            break;
        }

}

int ifValidLetter(char ch)
{


    if(ch>= 'a' && ch <='z')
        return 1;

    if(ch>= 'A' && ch <='Z')
        return 1;

    return 0;

}
int main()
{

    char ch[80];
    gets(ch);
    printPosition(ch);

}

