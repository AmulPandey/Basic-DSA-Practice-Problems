#include <iostream>
using namespace std;
 
class array
{
   int capacity;
   int lastindex;
   int *ptr;
  
  public:
   
   array(int);
   bool isempty();
   bool isfull();
   void append(int);
   void display();
   void insert(int,int);
   void del(int);
   int count();
   ~array();
   int search(int);
   int get(int);
   void edit(int,int);
   int getcap();
   void operator=(array &);

};

void array:: operator=(array &arr){
   capacity=arr.capacity;
   lastindex=arr.lastindex;
   
   if(ptr!=NULL)
     delete []ptr;
   ptr=new int[capacity];

   for (int i = 0; i <= lastindex; i++)
   {
      ptr[i]=arr.ptr[i];
   }

}

 int array::getcap(){

   return capacity;
 }

void array::edit(int index,int data){

if (index>=0 && index<=lastindex)
{
   ptr[index]=data;
}


}

int array::get(int i){

    return ptr[i];
}


void array::display(){

for (int i = 0;i<count(); i++)
{
    cout<<ptr[i]<<endl;
}
 cout<<endl;

}

int array::search(int data){

   for (int i = 0; i <= lastindex; i++)
      if (data==ptr[i])
         return i;
   return -1;     
   
   
}

array::~array(){

   delete[]ptr;
}


int array::count(){
    
    return lastindex+1;

}

void array::del(int index){
  for (int i = index; i <= lastindex; i++)
    ptr[i]=ptr[i+1];
  lastindex--;

}

void array::insert(int index,int data){
 
 if ((lastindex+1)== capacity)
   cout<<"array is already full";
 else if(index < 0 || index>lastindex+1)
 {
   cout<<"out of index";
 }
 else{ 
   for (int i = lastindex; i <=index; i--)
     ptr[i+1]=ptr[i];
   ptr[index]=data;
   lastindex++;
 }
}

void array::append(int data){
   if (lastindex+1==capacity)
      cout<<"array is already full";
   else{
      lastindex++;
      ptr[lastindex]=data;
   }


}

bool array::isfull(){

 return (lastindex==capacity-1);

}

bool array::isempty(){

 return (lastindex==-1);

}

array::array(int cap){

capacity = cap;
ptr = new int[cap];
lastindex=-1;

}

