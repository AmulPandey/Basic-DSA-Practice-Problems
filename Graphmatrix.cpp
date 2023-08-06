#include <iostream>
#include "dynamicarray.cpp"
using namespace std;


class graphmatrix{

int v_count;
int e_count;
int **adj;

public:
 
 int getv_count();
 void creategraph(int,int);
 void print();
 void printadj(int);
 dynarray& getadj(int);
 bool isisolated(int);
 ~graphmatrix();


};

int graphmatrix::getv_count(){

  return v_count;

}

graphmatrix::~graphmatrix(){

  for (int i = 0; i < v_count; i++)
       delete []adj[i];
  delete []adj;

}

bool graphmatrix:: isisolated(int nodenum){

bool flag = true;

if (nodenum<v_count & nodenum>=0)
    {
    
     for (int i = 0; i < v_count; i++)
     
         if (adj[nodenum][i]==1)
         {
             flag=false;
             break;
         }

    }

return flag;

}


void graphmatrix:: printadj(int nodenum){

if (nodenum<v_count & nodenum>=0)
{
    
for (int i = 0; i < v_count; i++)
{
    if (adj[nodenum][i]==1)
    {
        cout<<endl<<"V"<<i;
    }
    
}

}

}

dynarray& graphmatrix::getadj(int n){
   

   dynarray *p=new dynarray(v_count);
   if (n<v_count && n>=0)
  {
    
    for (int i = 0; i < v_count; i++)
   {
     if (adj[n][i]==1)
        p->append(i);
    
   }

  }

  return *p;

}

void graphmatrix::print(){

for (int i = 0; i < v_count; i++)
{
    for (int j = 0; j < v_count; j++)
    {
        cout<<adj[i][j]<<" ";
        cout<<endl;
    }
    
}

}

void graphmatrix:: creategraph(int vertex,int edge)
{

int u,v;
v_count=vertex;
e_count=edge;

adj=new int*[v_count];

for (int i = 0; i < v_count; i++)
     adj[i]=new int[v_count];

for (int i = 0; i < v_count; i++)
{
      for (int j = 0; j < v_count; j++)
      {
         adj[i][j]=0;
      }
      
}

for (int i = 0; i < e_count; i++)
{
    cout<<"\nEnter node number connecting graph";
    cin>>u>>v;
    adj[u][v]=1;
    adj[v][u]=1;

}

     
}
 
