#include <iostream>
using namespace std;
 
class dynarray
{
   int capacity;
   int lastindex;
   int *ptr;
  
  public:
   
   dynarray(int);
   bool isempty();
   void append(int);
   void display();
   void insert(int,int);
   void del(int);
   int get(int);
   int count();
   ~dynarray();
   int search(int);
   void doublearray();
   void halfarray();
   
};

void dynarray::doublearray(){

  int *temp = new int[2*capacity];
  for (int i = 0; i <= lastindex; i++)
      temp[i]=ptr[i];
  delete []ptr;
  ptr=temp;

  capacity=capacity*2;

}

void dynarray::halfarray(){

   int *temp = new int[capacity/2];
    for (int i = 0; i <= lastindex; i++)
      temp[i]=ptr[i];
  delete []ptr;
  ptr=temp;

  capacity=capacity/2;

}

void dynarray::display(){

for (int i = 0;i<capacity; i++)
{
    cout<<ptr[i]<<endl;
}


}

int dynarray::search(int data){

   for (int i = 0; i <= lastindex; i++)
      if (data==ptr[i])
         return i;
   return -1;     
   
}

dynarray::~dynarray(){

   delete[]ptr;
}


int dynarray::count(){
    
    return lastindex+1;

}

int dynarray::get(int index){

 return ptr[index];


}

void dynarray::del(int index){
    if (isempty())
    {
        cout<<"array is empty";
    }
    else if(index < 0 || index>lastindex+1)
   {
   cout<<"out of index";
    }
    else{
  for (int i = index; i <= lastindex; i++)
    ptr[i]=ptr[i+1];
  lastindex--;
  if (capacity/2>=lastindex+1 && capacity>1)
      halfarray();
}

}

void dynarray::insert(int index,int data){
 

 if(index < 0 || index>lastindex+1)
 {
   cout<<"out of index";
 }
 else{ 
     if (lastindex+1==capacity)
      {cout<<"array is already full,so here we double the capacity";
       doublearray();
      }
   for (int i = lastindex; i >=index; i--)
     ptr[i+1]=ptr[i];
   ptr[index]=data;
   lastindex++;
 }
}

void dynarray::append(int data){
   if (lastindex+1==capacity)
      {
        cout<<"array is already full,so here we double the capacity";
        doublearray();
      }
   
      lastindex++;
      ptr[lastindex]=data;
   

}

bool dynarray::isempty(){

 return (lastindex==-1);

}

dynarray::dynarray(int cap){

capacity = cap;
ptr = new int[cap];
lastindex=-1;

}

// int main(){
  
//   dynarray a(6);
//   a.append(34);
//   a.append(3);
//   a.append(76);
//   a.append(39);
//   a.append(76);
//   a.append(60);
  
  
//  return 0;
// }