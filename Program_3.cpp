//
//  Program_3.cpp
//  Data Structure
//
//  Created by Hansika Saxena on 01/10/20.
//  Copyright © 2020 Hansika Saxena. All rights reserved.
//

#include <iostream>
using namespace std;
class Node
{
   public:
   
       int data;
       Node *next;
};
class LinkedList {
public:
    int size;
    Node *head;
    LinkedList()
    {
        head = NULL;
        size =0;
    }
    void insert(int i,int n);
    int remove(int i);
    int search(int x);
    void concat(LinkedList b);
    void display();
};
 
void LinkedList::insert(int i,int n) {
    Node *new_node,*temp;
    int c=0;
    new_node = new Node;
        if(i==0){
            new_node->data = n;
            new_node->next = head;
            head=new_node;
            size++;
            }
        else{
           
            temp = head;
            while( c!=(i-1))
            {
                c++;
                temp = temp->next;
            }
            
                new_node->data = n;
                new_node->next = temp->next;
            temp->next=new_node;
                
            size ++;
             }
        }

int LinkedList::remove(int i) {
    int c=0,d;
   
        if(i==0){
            d=head->data;
            head=head->next;
            size --;
            }
        else{
            Node* temp = head;
            while(c!=(i-1))
             {
                 temp=temp->next;
                 c++;
             }
             d=temp->next->data;
            temp->next=temp->next->next;
            size --;
        }
    return d;
}

int LinkedList::search(int x) {
    int c=0;
    Node* new_node=head;
        if(size==0){
            std::cout<<"\nLink list is empty";
            }
        else{
            while(new_node!=NULL)
             {
               if(new_node->data == x)
               {
                   return c;
               }
                 c++;
                 new_node=new_node->next;
             }
           }
    return -1;
     }

void LinkedList::concat(LinkedList b){
    Node* temp = head;
    while(temp->next != NULL)
    temp=temp->next;
    temp->next=b.head;
}


void LinkedList::display() {
   Node* ptr;
   ptr = head;
   while (ptr != NULL) {
      std::cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
}
int main() {
    int n,i,e;
    char ch,choice='y';
    LinkedList A;
    LinkedList B;
    do
       {
    std::cout<<"\n1-insert an element in the beginning of the linked list";
    std::cout<<"\n2-insert an element in the ith index of the linked list";
    std::cout<<"\n3-remove an element from the beginning of the linked list";
    std::cout<<"\n4-remove an element from the ith index of the linked list";
    std::cout<<"\n5-search an element in the linked list";
    std::cout<<"\n6-concat two linked list";
    std::cout<<"\n7-display the linked list\n";
    std::cin>>ch;
 
    switch(ch)
    {
        case '1': std::cout<<"\nEnter element to be inserted";
                 std::cin>>n;
                 A.insert(0, n);
                 break;
        case '2':std::cout<<"\nEnter element and index for insertion";
                 std::cin>>n>>i;
                 A.insert(i, n);
                 break;
        case '3':
                 std::cout<<A.remove(0);
                 std::cout<<"\nElement Removed !\n";
                 A.display();
            break;
        case '4':std::cout<<"\nEnter index for removal";
                 std::cin>>i;
                  std::cout<<A.remove(i);
                 std::cout<<"\nElement Removed !\n";
              A.display();
                 break;
        case '5':std::cout<<"\nEnter element to be searched";
                std::cin>>e;
            int f;
            f=A.search(e);
            if(f==-1)
                std::cout<<"\nElement Not Found !";
            else
                std::cout<<"\nElement Found at index = "<<f;
                break;
            
        case '6':
                std::cout<<"\nSecond Linked List = ";
                do
                 {
                    
                 std::cout<<"\nEnter element to be inserted";
                 std::cin>>n;
                 B.insert(0, n);
                std::cout<<"\nEnter y if you want to enter more elements n otherwise";
                std::cin>>choice;
                 }while(choice=='y' || choice=='Y');
                A.concat(B);
                A.display();
                break;
            
        case '7':  A.display();
                break;
            
    }
    std::cout<<"\nEnter y if you want continue";
                      std::cin>>ch;
    }
    while(ch=='y' || ch=='Y');
    
   return 0;
}
