#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct node{

    int data;
    struct node *next;

}Node;


void reverse(Node **head){

    Node *prev = NULL;
    Node *current = (* head);
    Node *forward = NULL;

    while(current!=NULL){

        forward = current->next;
        current->next = prev;
        prev = current;
        current = forward;

    }

    (*head) = prev;




}
void push(Node ** head){

        int elem;
        Node *temp = (Node *)malloc(sizeof(Node));

        printf("Enter ");
        scanf("%d",&elem);

        temp->data = elem;

        temp->next = (*head);
        (*head) = temp;


}

void display(Node *head){


    Node *nxt = head;
    if(nxt==NULL)
        printf("Erooro");
    else
  while (nxt != NULL)
  {
     printf("%d ", nxt->data);
     nxt = nxt->next;
  }

}
int main(){

    Node *head = NULL;
    push(&head);
    push(&head);
    push(&head);

    display(head);
    printf("\n");
    reverse(&head);
    display(head);

    return 0;



}
