#include <iostream>
using namespace std;
 
void fib(int);

int main(){

 fib(3);

 return 0;
}

void fib(int x){

int a = 0,b = 1,c;

for (int  i = 1; i <= x; i++)
{
    if ( i == 1 || i == 2)
     cout<<i-1;
    else
     {c = a+b;
     cout<<c;
     a=b;
     b=c;}

}

}

//A number is Fibonacci if and only if one or both of (5*n2 + 4) or (5*n2 – 4) is a perfect square (Source: Wiki). Following is a simple program based on this concept.?
/* C++ program to check if x is a perfect square
#include <bits/stdc++.h>
using namespace std;

// A utility function that returns true if x is perfect
// square
bool isPerfectSquare(int x)
{
	int s = sqrt(x);
	return (s * s == x);
}

// Returns true if n is a Fibonacci Number, else false
bool isFibonacci(int n)
{
	// n is Fibonacci if one of 5*n*n + 4 or 5*n*n - 4 or
	// both is a perfect square
	return isPerfectSquare(5 * n * n + 4)
		|| isPerfectSquare(5 * n * n - 4);
}

// A utility function to test above functions
int main()
{
	for (int i = 1; i <= 10; i++)
		isFibonacci(i)
			? cout << i << " is a Fibonacci Number \n"
			: cout << i << " is a not Fibonacci Number \n";
	return 0;
}

*/


/*
#include<stdio.h>
int main()
{
    int n;
    printf("enter a number");
    scanf("%d",&n);

    if (n&1==0)
    {
        printf("even");
    }
    else
        printf("odd");
        
    return 0;
}
*/