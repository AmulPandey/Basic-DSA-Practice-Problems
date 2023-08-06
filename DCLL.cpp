#include <iostream>
#include<stdio.h>

using namespace std;
 
struct node{
   
   int data;
   node *next;
   node *prev;

};

class dcll{
 
     private:
           node *start;
     public:
           dcll();      
           void insertbeg(int);
           void insertlast(int);
           node* search(int);
           void insertafter(node *,int);
           void deletefirst();
           void deletelast();
           void deletenode(node *);
           ~dcll();


};

dcll::~dcll(){

  while(start)
      deletefirst();

}

void dcll::deletenode(node *ptr)
{

if(ptr){
 node *n= new node;
 n= ptr->next;
 
  if(start==start->next)
     start=NULL;
  else{
    ptr->prev->next=ptr->next;
    ptr->next->prev=ptr->prev;
      if (start==ptr)
        start=ptr->next;
      
  }
      

 delete ptr;
 }
}


void dcll::deletelast(){

 if(start){
 node *n= new node;
 n=start;

 if(start->prev==start){
   delete start;
   start=NULL;
 }  
 else{  
 n=start->prev;
 n->prev->next=start;
 start->prev=n->prev;
 delete n;  
 }
 
 }
 
}

void dcll::deletefirst(){

 if(start){
 node *n= new node;
 n=start;

  n->next->prev=n->prev;
    n->prev->next = n->next;
 
 if(start->next==start)
   start=NULL;
 else
   start=n->next;
 delete n;
 }

  
}


void dcll::insertafter(node *ptr,int value){

  if(start) {
node *n = new node;
n->data= value;
n->next=ptr->next;
n->prev=ptr;
ptr->next->prev=n;
ptr->next=n;

  
}
}


node* dcll::search(int value){
     
     if (start)
   {
     node *n;
     n=start;
    do
    {
        if (n->data==value)
           return n;
        n=n->next;   
    } while (n!=start);
    
    return NULL;

   }
}

void dcll::insertlast(int value){

  if(start){
     node *n = new node;
  n->data = value;
 n->next=start;
  n->prev=start->prev;
  start->prev->next=n;
  start->prev=n;
}    
else{
  node *n = new node;
    n->data = value;
  n->next = n;
  n->prev=n;
  start = n;
}

}

void dcll::insertbeg(int value){
if(start){
     node *n = new node;
  n->data = value;
  n->next=start;
  n->prev=start->prev;
  start->prev->next=n;
  start->prev=n;

  start=n;
 
}    
else{
  node *n = new node;
    n->data = value;
  n->next = n;
  n->prev=n;
  start= n;
}
} 

dcll::dcll()
{
    start=NULL;
}

int main(){
  
 
 return 0;
}
