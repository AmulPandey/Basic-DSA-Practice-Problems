#include <iostream>
#include <string.h>
using namespace std;

class cstring{
  
  char str[25];

public:

  void getstr(){

    cout<<"enter a string";
    cin>>str;

  }
  
  cstring operator+(cstring z){
   
   cstring s;
  strcpy(s.str,str);
  strcat(s.str,z.str);

  return s;

  }

 void show(){

    cout<<str;
 }

      int operator==(cstring &c);

};
 
 int cstring::operator==(cstring &c){

    for (int i = 0; str[i] != '\0'; i++)
    {
           for (int j = 0; c.str[j] != '\0'; j++)
           {
                if (str[i] == c.str[j])
                {
                    return 0;
                }
                else
                    return 1;
           }
           
           
        }  
        
}

/* int operator==(cstring c){


    for (int i = 0; str[i] != '\0'; i++)
    {
        
                if (str[i] == c.str[i])
                {
                    return 0;
                }
                else
                    return 1;
           }
 */          
           

int main(){
  

 cstring s1,s2;
 int result;

 s1.getstr();
 s2.getstr();

 (s1+s2).show();

 result = s1==s2;

 if (result == 0)
 {
    cout<<"equal string";
 }
 else
    cout<<"not equal string";


 return 0;
}


