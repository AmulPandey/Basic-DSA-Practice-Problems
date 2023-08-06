#include <iostream>
using namespace std;

class time{

    int hh=0,mm=0,ss=0;
public:
  friend  void operator>>(istream &in,time &t);

  friend void operator<<(ostream &out,time &t);
 // we can define friend function inside class in operator overloding.

  friend void operator==(time,time);

};

   void operator>>(istream &in,time &t){
   
       
          cout<<"enter hours:";in>>t.hh;cout<<endl;
          cout<<"enter minutes:";in>>t.mm;cout<<endl;
          cout<<"enter seconds:";in>>t.ss;cout<<endl;

    }


   void operator<<(ostream &out,time &t){

       out<<"hours :"<<t.hh;out<<endl;
       out<<"minutes :"<<t.mm;out<<endl;
       out<<"seconds :"<<t.ss;out<<endl;

   }

 
 void operator==(time t1,time t2){

    if (t1.hh == t2.hh && t1.mm == t2.mm && t1.ss == t2.ss)
    {
        cout<<"same time";
    }
    else
        cout<<"different time";
        
 }

int main(){
  time t1,t2;

  cin>>t1;
  cout<<t1;

  cin>>t2;
  cout<<t2;

  t1 == t2;

 // to print cout<<t1<<t2 we have to return type ostram& and return value in/out, because first time only cout and t1 will run..

 return 0;
}