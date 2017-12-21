#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct NODE {

    int data;
    struct NODE *link;

}node;

node *header = NULL;

void insertLinkedList(int item){


    node *temp = (node *)malloc(sizeof(node));
    node *ptr = (node *)malloc(sizeof(node));
    if(header==NULL){

        temp->data = item;
        temp->link = NULL;
        header = temp;
    }
    else{
        ptr = header;
        while(ptr->link!=NULL){
            ptr = ptr->link;
        }

        temp->data = item;
        temp->link = NULL;
        ptr->link = temp;

    }

}

void display(){

    node *ptr;
    ptr = header;
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr ->link;
    }

}

void deleteList(int item){
    node *ptr;
    ptr = header;
    int counter=1;
    int flag=0;
    if(ptr->data ==item){
        header = ptr->link;
        flag=1;
        printf("Element %d deleted at index number %d\n",item,counter);
    }
    else{

     while(ptr!=NULL){

         counter++;
         if((ptr->link)->data==item){
            ptr->link = ptr->link->link;
            printf("Element %d deleted at index number %d \n",item,counter);
            flag=1;
            break;
         }
         ptr = ptr->link;


     }


    }

    if(flag==0)
        printf("Element %d do not exist in List\n",item);

}

void searchList(int item){

    node *ptr;
    int counter=1;
    int flag=0;
    ptr = header;

    if(ptr->data == item){
        printf("Element %d found at index %d\n",item,counter);
        flag=1;

    }
    while(ptr!=NULL){

        counter++;
        if(ptr->link->data==item){

            flag=1;
            printf("Element %d found at index %d\n",item,counter);
            break;

        }

        ptr = ptr->link;

    }


    if(flag==0)
     printf("Element %d not found in the List",item);



}
int main(){

    node *ptr;
    int n,items;
    int choice;
    printf("Enter the number of elements to be inserted in linkedList initially\n");
    scanf("%d",&n);

    while(n-->0){

        printf("Enter ");
        scanf("%d",&items);
        insertLinkedList(items);

    }

     printf("Entered...\n");

     while(1){
     printf("\nEnter\n");
     printf("1 for Insertion\n2 for Deletion\n3 for Searching\n4 for Display\n5 for Exit\n");

     scanf("%d",&choice);
     switch(choice){

     case 1: printf("Enter element "); scanf("%d",&items); insertLinkedList(items);  break;
     case 2: printf("Enter the element to be deleted "); scanf("%d",&items); deleteList(items); break;
     case 3: printf("Enter the element to be searched "); scanf("%d",&items); searchList(items); break;
     case 4: printf("Display -  "); display(); break;
     case 5: exit(1);
     default: printf("Wrong Input, Try again");

     }

     }

    return 0;





}
