#include<stdio.h>
//#define '\0' null
int main(){

    char rWords[]= {"int,char,break,long,double,float,new,void,main,printf"};
  //  char program[] = {" void main()\{ int a,b; a=4; b=6; printf(\"%d\",a+b); \}"};
    char program[] = {" void main()\{ int a,b; printf(a); hello; \}"};
    int i=1;
    int pIndex=0;
    int lineNumber=1;
       char *line;
        int lIndex=0;




//        printf("\n");
   // puts(rWords);
    //printf("hello");

    while(program[pIndex]!='\0'){

        lIndex=0;
        line = (char *)malloc(sizeof(char)*100);
        while(program[pIndex]!='\0' && program[pIndex]!=';'){

            line[lIndex]=program[pIndex];
            lIndex++;
            pIndex++;

        }
        if(program[pIndex]=='\0') break;
        line[lIndex]= '\0';
        if(lIndex!=0)
       // puts(line);

  //      printf("hi");
       // printKeywords();
        printKeywords(line,rWords,lineNumber);
        lineNumber++;

        pIndex++;
                fflush(stdin);
                break;
    }




}
void printKeywords(char *line,char keywords[],int n){

    int l=0;
    int k=0;
    char *word;
        int w=0;

    //printf("hello %c",line[0]);

    puts(line);
    puts(keywords);
     while(1){
            if(line[l]=='\0'){
                printf("khatam");
                break;
            }
        w=0;
        word = (char *)malloc(sizeof(char)*50);
        while(line[l]!='\0' && line[l]!=' '){
            word[w]=line[l];
            l++;
            w++;

        }
        word[w]='\0';
        if(line[l]==
           '\0') {printf("khatam");break;}

        //printf("hi %d",w);
        puts(word);
      //  printWords(word,keywords,n);
         l++;
        fflush(stdin);


        //printf("hi %d",w);


    }





}

void printWords(char *ch,char key[],int n){

    char *keys;
    int k=0,i=0,k_=0;
    printf("hsdello");
    puts(ch);
    while(key[k]!='\0'){

        keys = (char *)malloc(sizeof(char)*50);
        k_=0;

        while(key[k]!='\0' && key[k]!=','){
            keys[k_]=key[k];
            k++;
            k_++;

        }

        keys[k_]='\0';

        if(key[k]=='\0'){ break;}
       // puts(keys);
        if(wordMatch(keys,key)){

            printf("\nKeyWord %s exist at line number %d",keys,n);
        }

        k++;
//         printf("hfello");
        fflush(stdin);



    }

}

int wordMatch(char *keys,char *ch){

    int k=0;
    int c=0;
    printf("\nchecking\n");
    puts(keys);
     printf("\nchecking\n");
    while(ch[c]!='\0'){


        if((ch[c]<'a' || ch>'z' ) && ch[c]==ch[k]){



        }
        else
            return 0;


    }

    return 1;

}
