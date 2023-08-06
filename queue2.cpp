#include<iostream>
#include<stdio.h>
using namespace std;

struct node{
int data;
node *next;

};

class queue{

        node *front, *rear;
    
 public:
        queue();
        bool isEmpty();
        void insert(int);
        int getrear();
        int getfront();
        void del();
        ~queue();
        int count();
        void sort();
        
}; 

void queue::sort() {
    if (isEmpty() || front->next == NULL) {
        return; // No need to sort if the queue is empty or has only one element
    }

    queue q1, q2;
    while (!isEmpty()) {
        int currentData = getfront();
        del();
        while (!q1.isEmpty() && q1.getfront() > currentData) {
            q2.insert(q1.getfront());
            q1.del();
        }
        q1.insert(currentData);
        while (!q2.isEmpty()) {
            q1.insert(q2.getfront());
            q2.del();
        }
    }

    front = q1.front;
    rear = q1.rear;
}


int queue::count(){

 node *n=new node;
 int c=0;

 n=front;
 while (n)
 {
    c++;
    n=n->next;
 }
 return c;


}

queue::~queue(){

    while (!isEmpty())
       del();
    
}


void queue::del(){

    node *n=new node;
    if (!isEmpty())
    {
        n=front;
        front=front->next;
        if (front==NULL)
           rear=NULL;
        delete n;   
        
    }
    
}

int queue::getfront()
{
   return front->data;

}

int queue::getrear()
{
   return rear->data;

}
void queue::insert(int value){

 node*n=new node;
 n->data=value;
 n->next=NULL;

   if(isEmpty())
    {
        front=rear=n;
    }
    else{
        rear->next=n;
        rear=n;
    }        

}

bool queue::isEmpty()
{
    return rear==NULL;
}

queue::queue(){
        front=NULL;
        rear=NULL;
    
}