#include "array.cpp"
class Extendedarray:public array
{

public:
      Extendedarray(int);
      int greatest();
      int sum();
      void sort();
      void swap_ind(int,int);
      void remdubli();
      void rotateR();

};

void Extendedarray::rotateR(){

   int temp;
    temp=get(count()-1);
   for (int i = count()-1; i > 0; i--)
   {
      edit(i,get(i-1));
   }
   edit(0,temp);

}

void Extendedarray::remdubli(){

  int i,j,t;

  for ( i = 0;i<count()-1;i++)
  {
     for ( j = i+1; j < count(); j++)
     {
       if (get(i)==get(j))
       {
         del(j);
         j--;  //because in case 10,4,10,10,7,7 we need to prevent value of j and due to lopp its increassing.
       }
       
     }
     
  }

}

void Extendedarray::swap_ind(int a,int b){
   int t;
for ( int i = 0; i < count()-1; i++)
{
   for (int j = i+1; j < count(); j++)
   {
      if (a==i && b==j)
      {
           t=get(i);
          edit(i,get(j));
          edit(j,t);
      }
      
   }
   
}
}

void Extendedarray::sort(){
  
  int i,j,t;

  for ( i = 0;i<count()-1;i++)
  {
     for ( j = i+1; j < count(); j++)
     {
       if (get(i)>get(j))
       {
          t=get(i);
          edit(i,get(j));
          edit(j,t);
       }
       
     }
     
  }
  
 cout<<"sorted array is:\n";

}


int Extendedarray::sum(){
int sum = 0;
for (int i = 0; i < count(); i++)
{
    sum=sum+get(i);

}
cout<<sum;

}



Extendedarray::Extendedarray(int cap):array(cap){}

int Extendedarray::greatest(){
 
  int max;
  if (isempty())
  {
    cout<<"\n Array is empty";
    return -1 ;
  }
  max=get(0);
  for (int i = 0; i < count(); i++)
  {
     if (max<get(i))
     {
        max=get(i);
     }
     
  }
   return max;

}
