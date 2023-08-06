
#include <iostream>
#include<stdio.h>

using namespace std;
 
struct node{
   
   int data;
   node *next;
   node *prev;

};

class dll{
 
     private:
           node *start;
     public:
           dll();      
           void insertbeg(int);
           void insertlast(int);
           node* search(int);
           void insertafter(node *,int);
           void deletefirst();
           void deletelast();
           void deletenode(node *);
           ~dll();


};

dll::~dll(){

  while(start != NULL)
      deletefirst();

}

void dll::deletenode(node *ptr)
{

      node *n = start;
        while(n->next != ptr)
             n=n->next;

   if(ptr->prev)
     { 
      n->next=ptr->next;
     }
   else
      start = ptr->next;

   if(ptr->next)
   {
        ptr->next->prev=n;
   }

      delete ptr;
}


void dll::deletelast(){

  if(start == NULL)
    cout<<"\nunderflow";
  else if(start->next == NULL){
      delete start;
      start=NULL;
  }
  else
  {
     node *t = start;
    while (t->next != NULL)
     t = t->next;
   t->prev->next=NULL; 
   delete t;
   
  }
 
}

void dll::deletefirst(){

  if(start->next != NULL)
  {
  node *n = new node;
  n = start;
  
  start = n->next;
  start->prev = NULL;

  delete n;
  }

}


void dll::insertafter(node *ptr,int value){

   node *n = new node;
   n->data=value;
   n->next = ptr->next;
   n->prev=ptr;
  
   ptr->next=n;

}


node* dll::search(int value){
     
  node *t = start;
 
    while (t != NULL)
    {
        if (t->data == value)
           return t;

        t = t->next;
    }
    
    return NULL;
   }


void dll::insertlast(int value){

   node *n = new node;
   n->data=value;
   n->next=NULL;

   if (start == NULL){
      n->prev=NULL;
      start = n;
   }
   else{
   node *t = start;
    while (t->next != NULL)
    {
        t=t->next;
    }
     t->next=n;
     n->prev = t;
     n->next=NULL;
   }

}

void dll::insertbeg(int value){

   node *n = new node;
   n->data=value;
   n->next=start;
   n->prev=NULL;
   if (start)
       start->prev=n;
   start= n;
}

dll::dll()
{
    start=NULL;
}

int main(){
  
 
 return 0;
}
