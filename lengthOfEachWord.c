#include<stdio.h>
#define n '\0'

 struct node2{

    char *apple;

};
 struct node{

    struct node2 shabad[200];
    int no;
    int index;

};
struct node  lists[200];





int removeSpace(char *ch,int *i){
    while(ch[*i]==' '){
        *i = *i + 1;
    }
}
void findWords(char *ch){

    int i=0;
    static int a[200];
    char *words[200];

    removeSpace(ch,&i);

    while(ch[i]!=n){

        int first = i;
        int last = first;
        while(ch[last]!=' ' && ch[last]!=n)
          last++;

        printf("\n");
             int length = last - first;

        a[length]++;
        char *word;
        word=malloc(200);
        int index=0;
        for(int j=first;j<last;j++)
            word[index++] = ch[j];

        word[index] = n;
       // printf("first= %d second = %d\n",first,last);
        //puts(word);
        insertInList(word,length);
       free(word);
        //

        i=last;


        if(ch[i]!=n)
            i++;
    }
 // printf("\n@@%s##\n",lists[2].shabad[ lists[2].index].apple);
    for(int i=0;i<200;i++)
        if(lists[i].no>0){

            printf("Total number of words of length %d are %d\n",i,lists[i].no);

            printf("the words are\n");


            for(int j=0;j<=lists[i].index;j++)
                puts(lists[i].shabad[j].apple);
                //lists[l].shabad[ lists[l].index].apple
            printf("\n\n");

    }

}



void insertInList(char *word,int l){



    //printf("%d",lists[l].shabad[ lists[l].index].apple);
    lists[l].no++;
    lists[l].index++;
  lists[l].shabad[ lists[l].index].apple = (char *)malloc(sizeof(char)*200);
    int k=0;
 //printf("%c",word[0]);
    while(word[k]!=n){


        lists[l].shabad[ lists[l].index].apple[k]=word[k]; k++;

    }

    lists[l].shabad[ lists[l].index].apple[k] = n;

   // lists[l].shabad[ lists[l].index].apple = word;

    //printf("\n$$##%s##\n",lists[l].shabad[ lists[l].index].apple);


}


int main(){

    char ch[200];
    for(int i=0;i<200;i++){
        lists[i].index=0;
        lists[i].no=0;
    }
    //char *ptr;
    //ptr = "hello";
    //puts(ptr);
     gets(ch);

    findWords(ch);


}


