
#include <iostream>
#include<stdio.h>

using namespace std;
 
struct node{
   
   int data;
   node *next;

};

class sll{
 
     private:
           node *start;
     public:
           sll();      
           void insertbeg(int);
           void insertlast(int);
           node* search(int);
           void insertafter(node *,int);
           void deletefirst();
           void deletelast();
           void deletenode(node *);
           ~sll();


};

sll::~sll(){

  while(start != NULL)
      deletefirst();

}

void sll::deletenode(node *ptr){

   if(start == NULL)
    cout<<"\nunderflow";

   else if(start == ptr){
         start = ptr->next;
         delete ptr;
      }
   else{
        node *n = start;
      
        while(n->next != ptr)
             n=n->next;
        n->next=ptr->next;
        delete ptr;
      }
   }


void sll::deletelast(){

  if(start == NULL)
    cout<<"\nunderflow";
  else if(start->next == NULL){
      delete start;
      start =NULL;
  }
  else
  {
     node *t = start;
    while (t->next->next != NULL)// t pointing second last node.
     t = t->next;
    
   delete t->next;
   t->next = NULL;
  }
 
}

void sll::deletefirst(){

  if(start->next != NULL)
  {
  node *n = new node;
  n = start;
  
  start = n->next;

  delete n;
  }

}


void sll::insertafter(node *ptr,int value){

   node *n = new node;
   n->data=value;

   n->next = ptr->next;
   ptr->next=n;

}


node* sll::search(int value){
     
  node *t = start;
 
    while (t!= NULL)//we have to take last node to so if t == NULL it means t is not pointng any node.
    {
        if (t->data == value)
           return t;

        t = t->next;
    }
    
    return NULL;
   }


void sll::insertlast(int value){

   node *t = start;
   node *n = new node;
   n->data=value;
   n->next=NULL;

   if (start == NULL)
      start = n;
   else{

    while (t->next != NULL)
    {
        t=t->next;
    }
    t->next=n;
   }

}

void sll::insertbeg(int value){

   node *n = new node;
   n->data=value;
   n->next=start;
   start= n;

}

sll::sll()
{
    start=NULL;
}


int main(){
  
 
 return 0;
}


/*
c code with return type

#include<stdio.h>
#include<stdlib.h>


struct node{
   
   int value;
   struct node *next;

};


void traverse(struct node* Node){
   
    printf("\nLinked List: ");
    
    // as linked list will end when Node is Null
    while(Node!=NULL){
        printf("%d ",Node->value);
        Node = Node->next;
    }
    
    printf("\n");
}



struct node *insertbeg(struct node* start,int data)
{

 struct node * ptr = (struct node*)malloc(sizeof(struct node));
 

 ptr->value = data;
 ptr->next = start;
 start = ptr;

  return start;

}

struct node *insertlast(struct node* start,int data)
{

struct node *ptr = (struct node*)malloc(sizeof(struct node));

ptr->next = NULL;
ptr->value = data;

struct node *temp = start;
while (temp->next != NULL)
{
   temp= temp->next;
}

temp->next = ptr;

return start;

}

struct node *insertafter(struct node* start,struct node* Node,int data)
{

 struct node * ptr = (struct node*)malloc(sizeof(struct node));
 

 ptr->value = data;
 ptr->next = Node->next;
 Node->next= ptr;
 
return start;
}

struct node *deletebeg(struct node* start)
{
  struct node *p = start;
  start = start->next;
  free(p);

  return start;
}

struct node *deletelast(struct node* start)
{
   struct node *p = start;
   struct node *q = start->next;

   while (q->next != NULL)
   {
        p = p->next;
        q = q->next;
   }
   
   p->next = NULL; 
   free(q);

   return start; 

}

struct node *deleteafter(struct node* start,struct node *Node)
{
  
   struct node *p = Node;
   struct node *q = Node->next;
   
   p->next=q->next;

   free(q);
   
   return start;
}

int main()
{
    struct node *first = (struct node*)malloc(sizeof(struct node));
    struct node *sec = (struct node*)malloc(sizeof(struct node));
    struct node *third = (struct node*)malloc(sizeof(struct node));

   struct node *start = first;
    
    first->value=50;
    first->next=sec;

    sec->value=100;
    sec->next=third;

    third->value=40;
    third->next=NULL;


    //traverse(start);
    //start = insertbeg(start,25);
    //traverse(start);
    //start = insertlast(start,55);
    //traverse(start);
    //start = insertafter(start,first,68);
    //traverse(start);

    //start = deletebeg(start);
    //traverse(start);
    //start = deletelast(start);
    //traverse(start);
    //start = deleteafter(start,first);
    //traverse(start);

    return 0;

}



*/