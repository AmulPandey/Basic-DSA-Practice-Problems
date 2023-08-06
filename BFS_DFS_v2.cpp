#include <iostream>

#include "queue1.cpp"
#include "graphlist.cpp"

using namespace std;

#include "stack1.cpp"



void dfs(graph &g,int s)
{

int n,u;
bool status[g.getv_count()];
for (int i = 0; i < g.getv_count(); i++)
      status[i]=false;

 stack S(g.getv_count());
 S.push(s);
 status[s]=true;
 while (!S.isempty())
 {
    n= S.peek();
    cout<<"  v"<<n;
    S.pop();
    dynarray adjnode= g.getadj(n);

   for(int i=0;i<adjnode.count();i++)
   {
      u=adjnode.get(i);
      if (status[u]==false)
      {
         S.push(u);
         status[u]=true;
      }
      
   }
   

 }
 
}

int main(){
  
  graph g;
  g.creategraph(6);
  dfs(g,0);
 
 return 0;
}