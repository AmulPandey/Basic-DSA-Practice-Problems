//BFS using graphmatrix.
#include <iostream>

#include "queue1.cpp"
#include "graphmatrix.cpp"

using namespace std;

void bfs(graphmatrix &g,int s)
{

int n,u;
bool status[g.getv_count()];
 Queue q(g.getv_count());
 q.insert(s);
 status[s]=true;
 while (!q.isEmpty())
 {
    n= q.getFront();
    cout<<"  v"<<n;
    q.del();
    dynarray adjnode= g.getadj(n);

   for(int i=0;i<adjnode.count();i++)
   {
      u=adjnode.get(i);
      if (status[u]==false)
      {
         q.insert(u);
         status[u]=true;
      }
      
   }
   

 }
 
}

//DFS using graphmatrix

#include "stack1.cpp"
void dfs(graphmatrix &g,int s)
{

int n,u;
bool status[g.getv_count()];
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
  
  graphmatrix g;
  g.creategraph(6,9);
  dfs(g,0);
 
 return 0;
}