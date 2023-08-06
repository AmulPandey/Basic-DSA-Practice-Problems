#include <iostream>
using namespace std;
 
class reverse{
      int i,n,m;
public:

 void setdata(int x){
      n=x;
 }

 void rev(){
      while (n)
      {
        m = n%10;
        n = n/10;
        cout<<m;
      }
      
 }


};

int main(){
   reverse r;
   r.setdata(456);
   r.rev();

 
 return 0;
}