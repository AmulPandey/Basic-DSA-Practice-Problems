#include <iostream>
using namespace std;

class biggest{
 int a;
public:
  void setdata(int x){
    a=x;
    }
  void max(biggest b2, biggest b3){
   if (a>b2.a)
   {
     if (a>b3.a)
     {
        cout<<a;
     }
     else
        cout<<b3.a;
   }
   else
       {
        if (b2.a>b3.a)
        {
             cout<<b2.a;
        }
        else
            cout<<b3.a;
       }

  }

};

int main(){
   biggest b1,b2,b3;

   b1.setdata(10);
   b2.setdata(2);  
   b3.setdata(10); 
   b1.max(b2,b3);
  
 return 0;
}