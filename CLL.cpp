#include<stdio.h>
#include<iostream>
 
struct node{
   int data;
   node *next;

}; 

class cll{

node *last;

   public:
         cll();
         void insertbeg(int);
         void insertlast(int);
         node* search(int);
         void insertafter(node*,int);
         void deletefirst();
         void deletelast();
         void deletenode(node*);
         ~cll();

};

cll::~cll(){

  while(last)
     deletefirst();

}

void cll::deletenode(node*ptr){
 if(ptr){
 node *n= new node;
 n= ptr->next;
  while(n->next!=ptr)
     n=n->next;
  n->next=ptr->next;   
  if(n==ptr)
     last=NULL;
  else if(n==last)
     last=n;     

 delete n;
 }

}

 void cll::deletelast(){
if(last){
 node *n= new node;
 n=last;
 
while(n->next!=last)
     n=n->next;
 if(n==last){
   delete last;
   last=NULL;
 }  
 else{  
 n->next = last->next;
 delete last;  
 last=n;  
 }
 
 }

 }

void cll::deletefirst(){

 if(last){
 node *n= new node;
 n=last->next;
 if(last->next==last)
   last=NULL;
 else
    last->next = n->next;
 delete n;
 }

}

void cll:: insertafter(node * ptr,int value){
 
if(last) {
node *n = new node;
n->data= value;
n->next=ptr->next;
ptr->next=n;
  if (ptr==last)
  {
   last=n;
  }
  
}

}

node* cll::search(int value){
   
   if (last)
   {
     node *n;
     n=last->next;
    do
    {
        if (n->data==value)
           return n;
        n=n->next;   
    } while (n!=last->next);
    
    return NULL;

   }
   
   

}

void cll::insertlast(int value){

if(last){
     node *n = new node;
  n->data = value;
  last->next=n;
   last=n;
}    
else{
 node *n = new node;
 n->data=value;
 n->next= n;
 last=n;
}
}

void cll::insertbeg(int value){

if(last){
     node *n = new node;
  n->data = value;
  n->next=last->next;
  last->next= n;
 
}    
else{
  node *n = new node;
  n->data = value;
  n->next = n;
  
  last->next= n;
  last = n;
}
  
}

cll::cll(){

   last = NULL;

}