//
//  Program_6.cpp
//  Data Structure
//
//  Created by Hansika Saxena on 20/10/20.
//  Copyright © 2020 Hansika Saxena. All rights reserved.
//

#include <iostream>
using namespace std;
int Stack[100], n=100, top=-1;
void push(int val) {
   if(top>=n-1)
   std::cout<<"Stack Overflow"<<endl;
   else {
      top++;
      Stack[top]=val;
   }
}
int pop() {
    int d;
    if(top<=-1){
   std::cout<<"Stack Underflow"<<endl;
    return 0;
    }
   else {
       d=Stack[top];
      top--;
       return d;
   }
}
void display() {
   if(top>=0) {
      std::cout<<"Stack elements are:";
      for(int i=top; i>=0; i--)
      std::cout<<Stack[i]<<" ";
      std::cout<<endl;
   } else
   std::cout<<"Stack is empty";
}
int main() {
   int ch, val;
   std::cout<<"1) Push in Stack"<<endl;
   std::cout<<"2) Pop from Stack"<<endl;
   std::cout<<"3) Display Stack"<<endl;
   std::cout<<"4) Exit"<<endl;
   do {
      std::cout<<"Enter choice: "<<endl;
      std::cin>>ch;
      switch(ch) {
         case 1: {
            std::cout<<"Enter value to be pushed:"<<endl;
            std::cin>>val;
            push(val);
            break;
         }
         case 2: {
             std::cout<<"The popped element is "<<pop()<<endl;
            break;
         }
         case 3: {
            display();
            break;
         }
         case 4: {
            std::cout<<"Exit"<<endl;
            break;
         }
         default: {
            std::cout<<"Invalid Choice"<<endl;
         }
      }
   }while(ch!=4);
   return 0;
}
