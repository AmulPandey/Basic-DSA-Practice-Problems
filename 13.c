#include<stdio.h>
#include<stdlib.h>

int traverse();
int insertion_beg();

struct node{

int data;
struct node *next;
};

int main()
{
    
    struct node *first=(struct node*)malloc(sizeof(struct node));
    struct node *sec=(struct node*)malloc(sizeof(struct node));
    struct node *third=(struct node*)malloc(sizeof(struct node));

    struct node *head=(struct node*)malloc(sizeof(struct node)); 

    
    first->data=50;
    first->next=sec;

    sec->data=100;
    sec->next=third;

    third->data=50;
    third->next=NULL;

    head = first;

   head = insertion_beg(head);
   traverse(head);
   insertion_last(head);
    traverse(head);
   

    return 0;
}

int traverse(struct node *head){
   
   while (head != NULL)
   {
       printf("%d\t",head->data);
       head = head -> next;
   }
    printf("\n");
   return 0;
 
}

int insertion_beg(struct node *head){
    
  struct node *temp = (struct node *)malloc(sizeof(struct node));

temp->data = 60;
temp->next = head;
    
    head = temp;
    return head;
}

int insertion_last(struct node *head){
 struct node *temp = (struct node *)malloc(sizeof(struct node));

 while (head -> next != NULL)
 {
    head = head->next;
 }
 
 head->next = temp;
 temp->data = 400;
 temp->next = NULL;
}