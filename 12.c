#include<stdio.h>


int fab(int);


int main()
{
    
    int m;

    printf("enter the number of terms of fib series you wanna see\n");
    scanf("%d",&m);

    
    for (int i = 1; i <= m; i++)
    {
        printf("%d",fab(i));
    }
    
    return 0;
}

int fab(int n){

if (n==1||n==2)
   return 1;
else   
   return (fab(n-1)+fab(n-2)) ; 

}