#include "array2.cpp"

using namespace std;
 
int main(){

  Extendedarray a(6);
  a.append(34);
  a.append(3);
  a.append(76);
  a.append(39);
  a.append(76);
  a.append(60);
  
 
  a.display();
  //a.sort();
  //a.rotateR();
  //a.remdubli();
  //a.swap_ind(2,3);
  a.display();

 
 return 0;
}