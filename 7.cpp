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
  
  friend complex operator+(complex,complex);

   void displayadd(){
     
     cout<<x<<"+"<<y<<"i\n";

  }

  };

  complex operator+(complex c1,complex c2){

    complex temp;

     temp.x = c1.x + c2.x;
     temp.y = c1.y + c2.y;

    return temp;
  }

int main(){

   complex c1,c2,c3;
   c1.setandprint(5,6);
   c2.setandprint(8,10);
   c3 = c1+c2;
   c3.displayadd();

 return 0;
}