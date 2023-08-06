#include <iostream>
#include <stdio.h>
using namespace std;

struct node{
 
 int data;
 node* next;
 node* prev;

};

class deque{
    private:
        node* front;
        node* rear;
    public:
        deque();
		void insertfront(int);
        void insertrear(int);
        void delfront();
        void delrear();
        int getrear();
        int getfront();
        ~deque();
        bool isempty();
        
};

bool isempty(){

  if (front)
     return true;
  return false;   
  
}

deque::~deque(){

    while(front)
      delfront();
}

int deque::getfront()
{
   return front->data;

}

int deque::getrear()
{
   return rear->data;

}

void deque::delrear(){

node *n;
if (rear)
{
    n=rear;
    if(front==rear)
      front=rear=NULL;
    else  
    {
    rear=rear->prev;  
    rear->next=NULL;
    }
    delete n;
}


}

void deque::delfront(){

node *n;
if (front)
{
    n=front;
    if(front==rear)
      front=rear=NULL;
    else  
    {
    front=front->next;  
    front->prev=NULL;
    }
    delete n;
}


}

void deque::insertrear(int value){
node *n = new node;
n->data=value;
n->next=NULL;
   if (rear)
     rear->next=n;
   else
     front=n;
rear=n;

}

void deque::insertfront(int value){
node *n = new node;
n->data=value;
n->prev=NULL;
n->next=front;
   if (front)
     front->prev=n;
   else
     rear=n;
front=n;

}

deque::deque(){
  rear=front=NULL;
}
