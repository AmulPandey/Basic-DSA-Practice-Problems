#include <iostream>
using namespace std;

class number{
    
    int x,y,z;

    public:
 void setdata(int a, int b, int c){

    x =a;y=b;z=c;
 }

 number operator-(){

number temp;
    temp.x= -x;
    temp.y= -y;
    temp.z= -z;
    
    return temp;
    
}

    void display()
        {
                cout<<" ";
                cout<<x<<"\t"<<y<<"\t"<<z;
        }
};

int main(){
  
  number n1,n2;

  n1.setdata(4,5,6);
  n2 = -n1;
  n2.display();
 
 return 0;

}