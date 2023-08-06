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
  
  complex operator+(complex c){
    complex temp;

     temp.x = x + c.x;
     temp.y = y + c.y;
    return temp;
  }

  void displayadd(){
     
     cout<<x<<"+"<<y<<"i\n";

  }

  complex operator+(){
       
       complex temp;

       temp.x= x+1;
       temp.y=y;

       return temp;

  }
};

int main(){

   complex c1,c2,c3,c4;
   c1.setandprint(5,6);
   c2.setandprint(8,10);
   c3 = c1+c2;
   c3.displayadd();
   c4 = +c3;
   c4.displayadd();

 return 0;
}