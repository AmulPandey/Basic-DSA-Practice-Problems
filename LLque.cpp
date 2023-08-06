#include <iostream>
#include<stdio.h>

using namespace std;
 
struct node{
   
   int data;
   node *next;

};


class poly{

  struct node{
    
    int coeffe;
    int degree;
    node *next;

  };
 
 node *start;

 void insert(int,int);


};

void poly::insert(int cofee,int power){

node *n;
n->coeffe=cofee;
n->degree=power;

node *t=start;
node *p=NULL;


if (start == NULL)
{
   n->next=NULL;
   start=n;

}
else{

p=t;
t=t->next;

while(t)
{
   if (power < t->degree)
   {
     p=t;
     t=t->next;
   }
   if(power > t->degree)
   {
    n->next=t;
    p->next=n;
    break;
   }


}

if (t==NULL)
{
    n->next=NULL;
    p->next=n;
}

}

}

class ll{
 
     private:
           node *start;
     public:
           int count();
           void reverse();
           node* middle();
           int iscycle();
           int countcycle();
           node* mergsortedlist(node*,node*);
           

};

// Function to merge two sorted linked lists
node* ll:: mergsortedlist(node* head1, node* head2) {
    // Handle the base cases where either list is empty
    if (head1 == nullptr) {
        return head2;
    }
    if (head2 == nullptr) {
        return head1;
    }

    // Create a new list that will be the merged list
    node* mergedHead;
    if (head1->data < head2->data) {
        mergedHead = head1;
        head1 = head1->next;
    } 
    else {
        mergedHead = head2;
        head2 = head2->next;
    }

    // Merge the remaining lists recursively
    node* current = mergedHead;
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data < head2->data) {
            current->next = head1;
            head1 = head1->next;
        } 
        else {
            current->next = head2;
            head2 = head2->next;
        }
        current = current->next;
    }

    // Append any remaining nodes from the two lists
    if (head1 != nullptr) {
        current->next = head1;
    } 
    else {
        current->next = head2;
    }

    return mergedHead;
}



int ll::countcycle(){

node *piche=start;
node *aage=start;
int count =1;

if(iscycle()){

do
{
   aage=aage->next->next;
   piche=piche->next;

} while (piche != aage);
 
do
{
   aage=aage->next;
   count++;

} while (piche != aage);

return count;

}
else
   return 0;

}

int ll::iscycle(){

node *piche=start;
node *aage=start;

do
{
   if(aage == NULL)
       return 0;
   if(aage->next!=NULL)    
      aage=aage->next->next;
   else
      return 0;
   piche=piche->next;
} while (piche != aage);
 
 return 1;

}

void ll::reverse(){

  node *n=start;
  node *n1=start->next;
  node *n2=start->next->next;
   
   while (n2)
   {
      n1->next=n;
      n=n1;
      n1=n2;
      n2=n2->next;
   }
    
    start->next=NULL;
    start=n1;

}

node* ll::middle(){

 /*

 node *t =start;
 int i =0;

 while(i<count()/2)
 {
    t=t->next;
    i++;

 }

return t;

}
 here we have to traverse loop 2 time first for count second for while while methode two is more efficient.
 */

node *n=start;
node *piche = start;
node *aage = start->next;

  while (n)
  {
   piche =piche->next;
   aage = aage->next->next;
  }
  
  return piche;
}

int ll::count(){

   node *t = start;
   int temp=0;

   while (t)
   {
     t=t->next;
     temp++;
   }
   
   return temp;

}   


int main(){
  
   // Create two sorted linked lists via object initialiser methode
    node* head1 = new node{1, new node{3, new node{5, nullptr}}};
    node* head2 = new node{2, new node{4, new node{6, nullptr}}};
 
 return 0;
}