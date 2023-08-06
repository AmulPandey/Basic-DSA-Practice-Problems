
#include <iostream>
using namespace std;
#include "stack1.cpp"


void swap(int*,int*);
void display(int*,int size);

void display(int *a,int size){

    for ( int i = 0; i < size; i++)
    {
        cout<<a[i]<<endl;
    }
    
}

void swap(int *a,int *b){

int t;

t=*a;
*a=*b;
*b=t;

}

//buble sorting
void bublesort(int*,int);

void bublesort(int *a,int size){


for (int i = 0; i < size-1; i++)
{
    for (int j = 0; j < size-i-1; j++)
    {
        if (a[j]>a[j+1])
        {
            swap(&a[i],&a[j]);
        }
        
    }
    
}


}

//modified buble sort
void mbublesort(int*a,int size);

void mbublesort(int *a,int size){


for (int i = 0; i < size-1; i++)
{
    int count=0;
    for (int j = 0; j < size-i-1; j++)
    {
        if (a[j]>a[j+1])
        {
            swap(&a[i],&a[j]);
            count=1;
        }
        
    }

    if(count==0)
      break;
    
}


}

//selection sort 1.0

void selectionsort(int*a,int size);

void selectionsort(int*a,int size){

for (int i = 0; i < size-1; i++)
  {
     for (int j = i+1; j < size; j++)
     {
        if (a[i]>a[j])
        {
            swap(&a[i],&a[j]);
        }
        
     }
     
  }


}

//selection sort 2.0

void selectionsort2(int arr[],int size);

void selectionSort2(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < size; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
    }
}


//insertion sort

void insertionsort(int a[],int size);

void insertionsort(int a[], int size) {
 for (int i = 1; i < size; i++) {
    int key = a[i];
    int j = i - 1;

    // Compare key with each element on the left of it until an element smaller than
    // it is found.
    // For descending order, change key<array[j] to key>array[j].
    while (key < a[j] && j >= 0) {
      a[j + 1] = a[j];
      --j;
    }
    a[j + 1] = key;
  }
}

//Quick sort

int quick(int a[], int left, int right) {
    int t;
    int loc = left;
   
    while (left < right) {
        while (left<right && a[loc]<a[right])
            right--;
        if (left==right)
            break;
        swap(&a[loc],&a[right]);
        loc=right;

        while (left<right && a[left] < a[loc])
            left++;
        if (left==right)
            break;
        swap(&a[left], &a[loc]);
        loc=left;

    }

   return loc;
}

void quicksort(int a[], int l,int u) {
   
   int loc;
   loc=quick(a,l,u);
   if (loc>l+1)
    quicksort(a,l,loc-1);
   if(loc<u-1) 
    quicksort(a,loc+1,u);

}

void quicksortloop(int a[], int l, int u) {
    stack lower(10), upper(10);
    lower.push(l);
    upper.push(u);

    while (!lower.isempty()) {
        int i = lower.peek();
        int j = upper.peek();
        lower.pop();
        upper.pop();
        int loc = quick(a, i, j); 

        if (loc > i + 1) {
            lower.push(i);
            upper.push(loc - 1);
        }
        if (loc < j - 1) {
            lower.push(loc + 1);
            upper.push(j);
        }
    }
}

//merge sort via loop

void merge(int a[],int n1,int i1,int b[],int n2,int i2,int c[],int i3){

  int i,j,k;
  for ( i = 0,j=0,k=0; i<n1&&j<n2; k++)
  {
       if (a[i+i1]<b[j+i2])
       {
          c[k+i3]=a[i+i1];
          i++;
       }
       else
           {
             c[k+i3]=b[j+i2];
             j++;
           }
       
  }

  while (i<n1)
  {
      c[k+i3]=a[i+i1];
      i++;
      k++;
  }
  
   while (j<n2)
  {
      c[k+i3]=b[j+i2];
      j++;
      k++;
  }
  


}

void mergepass(int src[],int size,int l,int dest[]){

    int j,mergecount,index,R,S;
    mergecount = size/(2*l);
    S=mergecount*2*l;
    R=size-S;
    for (j = 0; j < mergecount; j++)
    {
        index=j*2*l;
        merge(src,l,index,src,l,index+l,dest,index);
    }

    if (R<=l)
    {
       for (int i = 0; i < R; i++)
       {
             dest[S+i]=src[S+i];
       }
       
    }
    else
       merge(src,l,S,src,R-l,S+l,dest,mergecount*2*l);
    
    
    
}

void mergsortloop(int a[],int size)
{
    int l=1,b[size];
    while (l<size)
    {
        mergepass(a,size,l,b);
        mergepass(b,size,2*l,a);
        l=l*4; 
    }
    
}

//mergesort via recursion

void merging(int a[],int l,int m,int u)
{

    int L[m-l+1],R[u-m],i,j,k;
    for ( i = 0; i <m-l+1; i++)
        L[i]=a[l+i];
    for ( j = 0; j <m-l+1; j++)
        R[j]=a[m+1+j];    
    for ( i = 0,j=0,k=l; i <m-l+1 && j<u-m; k++)
    {
          if (L[i]<R[j])
          {
            a[k]=L[i];
            i++;
          }
          else{
            a[k]=R[j];
            j++;
          }
          
    }

    while (i<m-l+1)
    {
        a[k]=L[i]; 
        i++;
        k++;
    }
    while (i<m-l+1)
    {
        a[k]=R[j];
        j++;
        k++;
    }

    
}


void mergesort(int a[],int l,int u){

int m;
if(l<u){

    m=(l+u)/2;
    mergesort(a,l,m);
    mergesort(a,m+1,u);
    merging(a,l,m,u);
}


}





int main(){

int arr[5]={40,45,37,91,221};

  //bublesort(arr,5);
  //selectionsort(arr,5);
  //insertionsort(arr,5);
  // quicksort(arr,0,4);
  //mergsortloop(arr,5);
  mergesort(arr,0,4);
  display(arr,5);
 
 return 0;
}