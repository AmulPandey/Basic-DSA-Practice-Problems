#include <iostream>
using namespace std;
#include "dynamicarray.cpp"

struct node{
  int data;
  int vertex;
  node *next;
};

class adjlist{
  node *start;
  int vertex;
  public:
    adjlist();
    adjlist(int);
    void setvertex(int);
    node* getstart();
    void addnode(int ,int);
    void printlist();
    void removefirst();
    ~adjlist();

};

node* adjlist::getstart(){

  return start;
}

adjlist::~adjlist(){

   while(start)
    removefirst();

}

void adjlist::removefirst(){

 node *t;
 if (start)
 {
  t=start;
  start=start->next;
  delete t;
 }
 


}

void adjlist::printlist(){

  node *t = start;
  while(t)
  {
    
    cout<< "(" <<t->vertex<<","<<t->data<<")";
    t=t->next;
  }
}


void adjlist::addnode(int v,int value){

node *n=new node;
n->data=value;
n->vertex=v;
n->next=start;
start=n;

}

void adjlist::setvertex(int v){

   vertex=v;

}

adjlist::adjlist(){
    start = NULL;
}

adjlist::adjlist(int v){
    start = NULL;
    vertex=v;
}


class graph{

int v_count;
adjlist *arr;
public:
  graph();
  int getv_count();
  void creategraph(int);
  void printgraph();
  dynarray& getadj(int);
  ~graph();

};


graph::~graph(){

  delete []arr;
}


int graph::getv_count(){

  return v_count;

}

void graph::printgraph(){

for (int i = 0; i < v_count; i++)
{
     cout<<"\n";
     arr[i].printlist();
}


}


void graph::creategraph(int nodes){
   int n,v,data;
   v_count=nodes;
   arr= new adjlist[v_count];
   for (int i = 0; i < v_count; i++)
       {
        arr[i].setvertex(i);
        cout<<"how many neighoubers this node posses"<<i;
        cin>>n;
        for (int j = 0; j < n; j++)
        {
          cout<<"enter vertex number\n";
          cin>>v;
          cout<<"enter data to store";
          cin>>data;
          arr[i].addnode(v,data);
        }
        

       }
   


}

dynarray& graph::getadj(int n){
   

   dynarray *p=new dynarray(v_count);
   node *t=this->arr[n].getstart();
   while (t)
   {
     p->append(t->vertex);
     t=t->next;
   }

  return *p;

}

graph::graph(){

  v_count=0;
  arr=NULL;
}
 