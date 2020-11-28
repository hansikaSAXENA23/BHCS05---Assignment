//
//  Program_5.cpp
//  Data Structure
//
//  Created by Hansika Saxena on 20/10/20.
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
class CircularLinkedList {
public:
    int size;
    Node *head;
    CircularLinkedList()
    {
        head = NULL;
        size =0;
    }
    void insert(int i,int n);
    void insert_front(int n);
    void insert_back(int n);
    int remove(int i);
    void remove_x(int x);
    int search(int x);
    void concat(CircularLinkedList b);
    void display();
};
 void CircularLinkedList::insert_front(int n) {
 Node *new_node;

 new_node = new Node;
     new_node->data = n;
     if(head==NULL){
         head=new_node;
         new_node->next = head;
         size++;
         }
     else{
        new_node -> next = head -> next;
         head -> next = new_node;
          }
     size++;
     }

void CircularLinkedList::insert_back(int n) {
Node *new_node;

new_node = new Node;
    new_node->data = n;
       new_node -> next = head -> next;
        head -> next = new_node;
       head =new_node;
    size++;
    }

void CircularLinkedList::insert(int y,int n) {
    Node *new_node,*temp;
    new_node = new Node;
           
            temp = head;
            while( temp->data!=y)
            {
                temp = temp->next;
            }
            
                new_node->data = n;
                new_node->next = temp->next;
            temp->next=new_node;
             if(temp==head)
                 head=new_node;
            size ++;
            
        }

int CircularLinkedList::remove(int i) {
    int c=0,d=0;
   
        if(i==0){
            d=head->next->data;
            head->next=head->next->next;
            size --;
            }
        else if(i==(size-1))
        {
            d=head->data;
            Node* temp = head;
            while(c!=(size-2))
             {
                 temp=temp->next;
                 c++;
             }
            temp->next=temp->next->next;
            head = temp;
            size --;
        }

    return d;
}

void CircularLinkedList::remove_x(int x)
{
    if(head->data==x)
    {
        remove(size-1);
    }
    else{
        
        Node* temp = head;
            while(temp->next->data!=x)
            {
                temp=temp->next;
            }
    temp->next=temp->next->next;
    }
    size--;
}

int CircularLinkedList::search(int x) {
    int c=0;
    Node* new_node=head->next;
        if(size==0){
            std::cout<<"\nLink list is empty";
            }
        else{
            while(c<size)
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

void CircularLinkedList::concat(CircularLinkedList b){
    Node *temp;
    temp = head->next;
    head->next=b.head->next;
    b.head->next=temp;
    head=b.head;
    size=size+b.size;
}


void CircularLinkedList::display() {
    int c=0;
    Node* ptr;
   ptr = head->next;
   while (c<size-1) {
       c++;
      std::cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
}
int main() {
    int n,i,e;
    char ch,choice='y';
    CircularLinkedList A;
    CircularLinkedList B;
    do
          {
       std::cout<<"\n1-insert an element in the beginning of the linked list";
       std::cout<<"\n2-insert an element x after an element y in the linked list";
       std::cout<<"\n3-insert an element in the end of the linked list";
       std::cout<<"\n4-remove an element from the beginning of the linked list";
       std::cout<<"\n5-remove an element x from the linked list";
       std::cout<<"\n6-remove an element from the end of the linked list";
       std::cout<<"\n7-search an element in the linked list";
       std::cout<<"\n8-concat two linked list";
       std::cout<<"\n9-display the linked list\n";
       std::cin>>ch;
    
       switch(ch)
       {
           case '1':
                    std::cout<<"\nEnter element to be inserted\n";
                    std::cin>>n;
                    A.insert_front(n);
                    break;
           case '2':
                    std::cout<<"\nEnter x and y :\n";
                    std::cin>>n>>i;
                    A.insert(i, n);
                    break;
           case '3':
                   std::cout<<"\nEnter element to be inserted\n";
                   std::cin>>n;
                   A.insert_back(n);
                   break;
           case '4':
                   std::cout<<A.remove(0);
                   std::cout<<"\nElement Removed !\n";
                   A.display();
                   break;
           case '5':
                   std::cout<<"\nEnter element for removal\n";
                   std::cin>>i;
                   A.remove_x(i);
                   std::cout<<"\nElement Removed !\n";
                   A.display();
                   break;
           case '6':
                   std::cout<<A.remove(A.size-1);
                   std::cout<<"\nElement Removed !\n";
                   A.display();
                   break;
           case '7':
                   std::cout<<"\nEnter element to be searched\n";
                   std::cin>>e;
                   int f;
                   f=A.search(e);
                   if(f==-1)
                       std::cout<<"\nElement Not Found !";
                   else
                       std::cout<<"\nElement Found at index = "<<f;
                   break;
           case '8':
                   std::cout<<"\nSecond Linked List = ";
                   do
                    {
                       
                        std::cout<<"\nEnter element to be inserted\n";
                        std::cin>>n;
                        B.insert_front(n);
                        std::cout<<"\nEnter y if you want to enter more elements n otherwise\n";
                        std::cin>>choice;
                    }while(choice=='y' || choice=='Y');
                   A.concat(B);
                   A.display();
                   break;
               
           case '9':
                   A.display();
                   break;
               
       }
       std::cout<<"\nEnter y if you want continue\n";
                         std::cin>>ch;
       }
       while(ch=='y' || ch=='Y');
       
   return 0;
}
