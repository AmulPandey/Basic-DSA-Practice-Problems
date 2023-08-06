#include <iostream>
using namespace std;

class mat{

  int arr[3][3];
  int i,j;

public:

  void setdata(){

    cout<<"enter 9 numbers\n";

    for ( i = 0; i < 3; i++)
    {
       for ( j = 0; j < 3; j++)
       {
          cin>>arr[i][j];
       }
       
    }
    
  }
 
 mat operator-(){
    
    mat temp;
  
   for ( i = 0; i < 3; i++)
    {
       for ( j = 0; j < 3 ; j++)
       {
          temp.arr[i][j] = -arr[i][j];
          
       }
   
    }
   return temp;

    
 }
  
 void display()
 {

    for ( int i = 0; i < 3; i++)
    {
       for ( int j = 0; j < 3 ; j++)
         {
             cout<<arr[i][j];
         }
       
    }
 } 

};

int main(){
  
  mat m1,m2;

  m1.setdata();
  m1.display();
  m2 = -m1;
  m2.display();
 
 return 0;

}