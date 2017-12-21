#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define  null NULL
#define m 20
#define n 50
typedef struct Snake{

    char value;
    int x;
    int y;
    struct Snake *next;

}snake;

typedef struct Food{

    char value;
    int x;
    int y;

}food;



void initializeCanvas(char ch[m][n]){
    int i,j;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            ch[i][j]= ' ';


}
void displayCanvas(char ch[m][n]){
    int i,j;
    for(i=0;i<m;i++){

        for(j=0;j<n;j++)
            printf("%c",ch[i][j]);
        printf("\n");
    }



}
void insertLinkedList(snake ***head,char v,int x1,int y1){

    snake *temp = (snake *)malloc(sizeof(snake));
    snake *temp1 = **head;
    temp->value =v;
    temp->x = x1;
    temp->y = y1;
    temp->next=NULL;

    if(**head==NULL){

        **head = temp;
        return;


    }

    while(temp1->next!=null){

        temp1 = temp1->next;
    }
    temp1->next = temp;




}

void createSnake(snake **head){

   insertLinkedList(&head,'H',25,10);
   insertLinkedList(&head,'#',25,11);
   insertLinkedList(&head,'#',25,12);
   insertLinkedList(&head,'#',25,13);

  insertLinkedList(&head,'#',25,14);

}
void updateCanvas(snake **head,char ch[m][n]){

    snake *temp = *head;
    int i,j;
    initializeCanvas(ch);


    while(temp!=NULL){

        j = temp->x;
        i = temp->y;
        ch[i][j] = temp->value;
        temp = temp->next;

    }


}

void changeLinkedList(snake **head,int x1,int y1){
        int i,j;
        snake *ptr = *head;
        snake *temp = (snake *)malloc(sizeof(snake));
        snake *temp2;

        temp->x = ptr->x;
        temp->y = ptr->y;
        temp->next=NULL;



        while(ptr->next!=NULL){

             temp2 = (snake *)malloc(sizeof(snake));
             temp2->x = ptr->next->x;
             temp2->y = ptr->next->y;

             ptr->next->x = temp->x;
             ptr->next->y = temp->y;

             temp->x = temp2->x;
             temp->y = temp2->y;

             free(temp2);
             ptr = ptr->next;

        }



        free(temp);

        i = (*head)->x + x1;
        j = (*head)->y  + y1;



        (*head)->x   += x1;
      (*head)->y   += y1;


      ptr = *head;
        if(ptr->x == n){

            ptr->x=0;

        }
         if(ptr->x == -1)
            ptr->x=n-1;
      if(ptr->y == m)
            ptr->y = 0;
        if(ptr->y == -1)
            ptr->y = m-1;




}
void createFood(snake **head,char ch[m][n],food *f){

       // should only be called once
       srand(time(NULL));
       int x1,y1;

    do{
    x1 =  rand()%n;
    y1 =  rand()%m;

    }while(isNotSafe(&head,x1,y1));

   // ch[y1][x1] = '$';
    f->value = '$';
    f->x = x1;
    f->y = y1;

}
int isNotSafe(snake ***head,int x1,int y1){

    snake *ptr = **head;

    while(ptr!=NULL){

        if(ptr->x==x1 && ptr->y==y1 || (x1==0 || y1==0 || x1==n-1 || y1==m-1)){
            printf("not safe");
            return 1;
        }

        ptr = ptr->next;

    }

    return 0;






}
void insertingFood(char ch[m][n],food *f){

      ch[f->y][f->x]=f->value;



}
void increaseSnakeLength(snake **head){
    snake *ptr = *head;
     while(ptr->next!=NULL){
            ptr = ptr->next;

     }
      insertLinkedList(&head,'#',ptr->x,ptr->y);

}

int foodEaten(snake **head,food *f){

    snake *temp = *head;
    int a = temp->x;
    int b = temp->y;
    int c = f->x;
    int d = f->y;
    if(a==c && b==d)
        return 1;

    return 0;


}

int isGameOver(snake **head){


    int x = (*head)->x;
    int y = (*head)->y;

    snake *ptr = (*head)->next;
    while(ptr!=NULL){

        if(ptr->x==x && ptr->y==y)
            return 1;
        ptr = ptr->next;


    }


}
void saveTheGame(snake **head,int Score){

    FILE *fp;
    snake *ptr = *head;
    fp = fopen("savedGame.txt","w");

    while(ptr!=NULL){

        fprintf(fp,"(%c,%d,%d)",ptr->value,ptr->x,ptr->y);
        ptr = ptr->next;

    }
    fprintf(fp,"$%d",Score);
    fclose(fp);

}

int getPreviousNodes(snake **head,char string[]){

    char ch;
    int i=0,j;
    int num,x,y;
    int power=1;
    i++;


    while(string[i]!='$'){
        power=0;
        num=0;
        ch = string[i];

        i = i+ 2; //to pass through comma
        j=i;

        while(string[j++]!=','){

            power++;
        }
        power--;

        while(string[i]!=','){

            num = num + (string[i] - '0')*getPower(10,power--);

            i++;
        }


        x = num;
        i++; //to pass through comma
        power=0;
        j=i;
        while(string[j++]!=')'){

            power++;
        }
        power--;
        num=0;

        while(string[i]!=')'){

            num = num + (string[i] - '0')*getPower(10,power--);
            i++;
        }

        y= num;

        insertLinkedList(&head,ch,x,y);


        if(string[i+1]!='$')
         i = i+2;
        if(string[i+1]=='$') break;







    }
    i+=2;
    j=i;
    power=0;
        while(string[j++]!='\0'){

            power++;
        }
        power--;
        num=0;

        while(string[i]!='\0'){

            num = num + (string[i] - '0')*getPower(10,power--);
            i++;
        }


    return num;






}
int getPower(int elem,int n1){

    if(n1==0) return 1;

    return elem * getPower(elem,n1-1);

}
int resetTheGame(snake **head){

   snake *temp = *head;
   free(temp);

   return 0;
}
int main(){



    snake *head = NULL;
    food f;
    int flag = 0;
    int Score = 0;
    char canvas[m][n];
    char dir;
    char string[500];
    char ch;
    FILE *fp =NULL;
    int index=0;
    fp = fopen("savedGame.txt","r");


    if(fp!=NULL){
           fscanf(fp,"%[^\n]", string);
            Score = getPreviousNodes(&head,string);

    }
     printf("Score = %d\n",Score);



    //Here we initialize the matrix with spaces
    initializeCanvas(canvas);
    // Here we give some default values to snake
    if(fp==NULL)
        createSnake(&head);


    // Here we insert the values from linked list to matrix
    updateCanvas(&head,canvas);
     // Here we give some default values to food
    createFood(&head,canvas,&f);


    // Here we display the matrix
    displayCanvas(canvas);



    while(1){


        dir = getch();
         if(foodEaten(&head,&f)){
                        createFood(&head,canvas,&f);
                         Score += 10;
                        increaseSnakeLength(&head);

                  }

          if(isGameOver(&head)){

            printf("\nGame Over");
            printf("\nScore = %d\n",Score);
            break;

          }
          if(dir=='r' || dir=='R'){
            system("cls");
            Score = 0;
            head=NULL;
            printf("\nScore = %d\n",Score);
            createSnake(&head);
            updateCanvas(&head,canvas);
            createFood(&head,canvas,&f);
            displayCanvas(canvas);
           // fclose(fp);
           // fp = fopen("savedGame.txt", "w");
            //fclose(fp);
            printf("w %d",remove("savedGame.txt"));
            continue;
          }

         if(dir=='s' || dir=='S'){


            saveTheGame(&head,Score);
            printf("\nGame Saved");
             printf("\nScore = %d\n",Score);
             break;

         }

        if(dir=='8'){

                  if(flag == 2) continue;

                  flag = 8;
                  changeLinkedList(&head,0,-1);
                  updateCanvas(&head,canvas);
                  system("cls");
                  printf("Score = %d\n",Score);
                  insertingFood(canvas,&f);
                 displayCanvas(canvas);



        }
        else if(dir=='6'){
                    if(flag == 4) continue;

                  flag = 6;
                changeLinkedList(&head,1,0);

                  updateCanvas(&head,canvas);

                  system("cls");
                  printf("Score = %d\n",Score);
                  insertingFood(canvas,&f);

                displayCanvas(canvas);



        }
        else if(dir=='2'){

                    if(flag == 8) continue;

                  flag = 2;
                  changeLinkedList(&head,0,1);
                  //canvas[head->x][head->y] = 'H';
                  updateCanvas(&head,canvas);
                  system("cls");
                  printf("Score = %d\n",Score);
                  insertingFood(canvas,&f);

                displayCanvas(canvas);

        }
        else if(dir=='4'){
                    if(flag == 6) continue;

                  flag = 4;
                  changeLinkedList(&head,-1,0);
                  //canvas[head->x][head->y] = 'H';
                  updateCanvas(&head,canvas);
                  system("cls");
                  printf("Score = %d\n",Score);
                  insertingFood(canvas,&f);
                  displayCanvas(canvas);
        }

        else{
            printf("Ending Score = %d",Score);
            break;
        }
        fflush(stdin);
}
}



//srand(time(NULL));   // should only be called once
//int r = rand();
