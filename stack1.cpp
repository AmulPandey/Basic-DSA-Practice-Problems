#include "array.cpp"

class stack:private array{

public:
  stack(int);
  void push(int);
  void pop();
  int peek();
  ~stack();
  virtual bool isfull();
  virtual bool isempty();
  int getstacksize();
  void operator=(stack &);
};

void stack::operator=(stack &s)
{
array::operator=(s);
}

int stack::getstacksize(){

 return  getcap();
}

bool stack::isempty(){

return array::isempty();

}

bool stack::isfull(){

return array::isfull();

}

stack::~stack(){}

int stack:: peek(){

if (!isempty())
   return get(count()-1);

}

void stack::pop(){
if (isempty())
{
    cout<<"\n Stack Underflow";
}
else
   del(count()-1);

}

void stack::push(int value){

if (isfull())
{
    cout<<"\n Stack Overflow";
}
else
  append(value);

}

stack::stack(int cap):array(cap){}


void reversestack(stack &s1){

 stack s2(s1.getstacksize());

 while(!s1.isempty())
 {

  s2.push(s1.peek());
  s1.pop();

 }

 s1=s2;
}

//function to get info of min element in stack all time.
void pushinstack(stack &s,stack &minstack,int data)
{
s.push(data);
if (minstack.isempty())
      minstack.push(minstack.peek());
else
     minstack.push(data);      
}

void popinstack(stack &s,stack &minstack)
{
      s.pop();
     minstack.pop();      
}


// int main(){
  
//  stack s(10);

//  s.push(3);
//  s.push(4);
//  s.push(7);
//  s.push(89);
//  s.push(6); 
//  s.push(9);

//  cout<<endl<<s.peek();
//  reversestack(s);
//   cout<<endl<<s.peek();
//  return 0;
// }