
void printnat(int n);
void odd(int n);
int sumnat(int  n);
int sumeven(int n);
int fact(int n);
int sumdigit(int n);
void decitobin(int n);
int fib(int n);
int hcf(int,int);
int power(int,int);

#include <iostream>
using namespace std;
 
int main(){
  
//printnat(5);

//odd(5);
//int sum = sumnat(5);
//cout<<sum;

//int sum = sumeven(5);
//cout<<sum;

//int sum = fact(5);
//cout<<sum;

//int sum = sumdigit(50);
//cout<<sum;

//decitobin(35);

//int num = fib(10);
//cout<<num;

//int num = hcf(10,12);
//cout<<num;

int num = power(10,2);
cout<<num;

 return 0;
}

void printnat(int n)
{

 if (n==1)
    cout<<'1';
 else{   
 printnat(n-1);   
 cout<<n;
 }

}

void odd(int n){

 if (n==1)
    cout<<'1';
 else{   
 odd(n-1);   
 cout<<(2*n-1);
 }


}

int sumnat(int  n)
{
 if (n==1)
    return 1;
 else
 {     
 int res;
 res= n + sumnat(n-1); 
 return res;
 }

}

int sumeven(int n){

 if (n==1)
    return 2;
 else
 {     
 int res;
 res =  2*n + sumeven(n-1); 
 return res;
 }

}

int fact(int n)
{

if (n==1)
    return 1;
 else
 {     
 int res;
 res= n * fact(n-1); 
 return res;
 }

}

int sumdigit(int n)

{

if (n==0)
    return 0;
 else
 {     
 int res;
 res= (n%10) + sumdigit(n/10); 
 return res;
 }

}

void decitobin(int n){

 if(n>0)
 {   
      
  decitobin(n/2);
  cout<<n%2;

 }

}

int fib(int n){

int res;

if (n==1)
   return 0;
if (n==2)
    return 1;
else
   {
       res= fib(n-1)+fib(n-2);
   }
   
   return res;
}

int hcf(int num1,int num2){

{
   if (num1 == 0)
      return num2;

   if (num2 == 0)
      return num1;

   // base case
   if (num1 == num2)
      return num1;

   if (num1 > num2)
      return hcf(num1 - num2, num2);

   return hcf(num1, num2 - num1);
}


}

int power(int n,int m){

if(n==0)
  return 0;
if(m==0 && n != 0)  
  return 1;
 
 return n*power(n,m-1);
}