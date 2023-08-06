
#include <iostream>
#include <stdio.h>
using namespace std;

struct node{

    int data;
    node *next;
};

class stack{
    node *top;
    public:
      stack();
      stack(stack &);
      void push(int);
      int peek();
      void pop();
      ~stack();
      bool isempty();
      bool palindromchecker(int);
      void reverse();
      void operator=(stack &S);
      string infixtopostfix(string &);
      int evaluatePostfix(string& postfix);
};

int stack::evaluatePostfix(string& postfix) {
    stack s;

    for (char c : postfix) {
        if (isdigit(c)) {
            s.push(c - '0');
        } else {
            int operand2 = s.peek();
            s.pop();
            int operand1 = s.peek();
            s.pop();

            switch (c) {
                case '+':
                    s.push(operand1 + operand2);
                    break;
                case '-':
                    s.push(operand1 - operand2);
                    break;
                case '*':
                    s.push(operand1 * operand2);
                    break;
                case '/':
                    s.push(operand1 / operand2);
                    break;
            }
        }
    }

    return s.peek();
}


string stack::infixtopostfix(string &infix){

    string postfix;

    for (char c : infix) {
        if (c == ' ')
            continue;

        if (isalnum(c)) {
            postfix += c;
        } else if (c == '(') {
            push(c);
        } else if (c == ')') {
            while (!isempty() && peek() != '(') {
                postfix += peek();
                pop();
            }
            pop(); // Discard the opening parenthesis
        } else {
            while (!isempty() && peek() != '(' && c <= peek()) {
                postfix += peek();
                pop();
            }
            push(c);
        }
    }

    while (!isempty()) {
        postfix += peek();
        pop();
    }

    return postfix;
}



bool stack::isempty(){

 return (top == nullptr);

}

void stack::operator=(stack &S)
{
    node *t,*n,*p=NULL;
    t=S.top;
    while(t)
    {
        n=new node;
        n->data=t->data;
        if(top==NULL)
            top=n;
        else
            p->next=n;
        t=t->next;
        p=n;
    }
    if(p!=NULL)
        p->next=NULL;
}
stack::stack(stack &S)
{
    node *t,*n,*p=NULL;
    t=S.top;
    while(t)
    {
        n=new node;
        n->data=t->data;
        if(top==NULL)
            top=n;
        else
            p->next=n;
        t=t->next;
        p=n;
    }
    if(p!=NULL)
        p->next=NULL;
}
void stack::reverse()
{
    node *t1,*t2;
    if(top && top->next)
    {
        t2=NULL;
        do
        {
            t1=top;
            top=top->next;
            t1->next=t2;
            t2=t1;
        } while (top->next!=NULL);
        top->next=t1;
    }
}

int lenth(int n){
int count =0;
while(n){

  n=n/10;
  count++;

}
return count;

}

bool stack::palindromchecker(int x){

stack s;
int l = lenth(x);
int i=l/2;

  while(i)
  {
    s.push(x%10);
    x=x/10;
    i--;
  }
  if (l%2!=0)
  {
    x=x/10;
  }
  
  while (x)
  {
    if (x%10 == s.peek())
    {
      s.pop();
      x=x/10;
    }
    else
        return false;
  }

  return true;
  
}

stack::~stack(){

while (top!=NULL)
      pop();

}

void stack::pop(){
   
   node *n;
   n=top;
   top=top->next;
   delete n; 

}

int stack::peek(){

  if (top==NULL){
     cout<<"endl"<<"stack is empty";
     return 1;}
  else
    return top->data;
}

void stack::push(int value){

node *n= new node;
n->data=value;
n->next=top;
top=n;

}

stack::stack(){

 top=NULL;

}