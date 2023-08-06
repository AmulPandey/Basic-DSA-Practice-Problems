#include <iostream>
using namespace std;
 
class complex{
    int x,y;
  public:
   void setandprint(int a, int b)  {
       x = a;
       y = b;
       cout<<a<<"+"<<b<<"i\n";
   }
  
  complex add(complex c){
    complex temp;

     temp.x = x + c.x;
     temp.y = y + c.y;
    return temp;
  }

  void displayadd(){
     
     cout<<x<<"+"<<y<<"i\n";

  }
};

int main(){

   complex c1,c2,c3;
   c1.setandprint(5,6);
   c2.setandprint(8,10);
   c3 = c1.add(c2);
   c3.displayadd();

 return 0;
}