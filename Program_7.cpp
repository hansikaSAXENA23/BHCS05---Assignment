//
//  Program_7.cpp
//  Data Structure
//
//  Created by Hansika Saxena on 20/10/20.
//  Copyright © 2020 Hansika Saxena. All rights reserved.
//

#include <iostream>
using namespace std;
class Node {
public:
   int data;
    Node *next;
};
 Node* top = NULL;
void push(int val) {
    Node* newnode = (Node*) malloc(sizeof(Node));
   newnode->data = val;
   newnode->next = top;
   top = newnode;
}
int pop() {
    int d;
    if(top==NULL){
   std::cout<<"Stack Underflow"<<endl;
        return 0;
    }
   else {
       d=top->data;
      top = top->next;
       return d;
   }
}
void display() {
   Node* ptr;
   if(top==NULL)
   std::cout<<"stack is empty";
   else {
      ptr = top;
      std::cout<<"Stack elements are: ";
      while (ptr != NULL) {
         std::cout<< ptr->data <<" ";
         ptr = ptr->next;
      }
   }
   std::cout<<endl;
}
int main() {
   int ch, val;
   std::cout<<"1) Push in stack"<<endl;
   std::cout<<"2) Pop from stack"<<endl;
   std::cout<<"3) Display stack"<<endl;
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
                 std::cout<<"The popped element is "<< pop() <<endl;
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
