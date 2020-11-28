//
//  Program_4.cpp
//  Data Structure
//
//  Created by Hansika Saxena on 02/10/20.
//  Copyright © 2020 Hansika Saxena. All rights reserved.
//

#include <iostream>
using namespace std;
class Node
{
   public:
   
       int data;
       Node *next,*prev;
};
class DoublyLinkedList {
public:
    int size;
    Node *head,*tail;
    DoublyLinkedList()
    {
        head =tail= NULL;
        size =0;
    }
    void insert(int i,int n);
    void insert_head(int n);
    void insert_tail(int n);
    int remove(int i);
    int search(int x);
    void concat(DoublyLinkedList b);
    void display();
};
 void DoublyLinkedList::insert_head(int n)
{
     Node *new_node;
    new_node=new Node;
    new_node->data=n;
    new_node->next=head;
    new_node->prev=NULL;
    if(head==NULL)
    {
        head=tail=new_node;
    }
    else
    {
        head->prev=new_node;
        head=new_node;
    }
    size++;
}
void DoublyLinkedList::insert_tail(int n)
{
    Node *new_node;
       new_node=new Node;
       new_node->data=n;
       new_node->prev=tail;
       new_node->next=NULL;
       if(tail==NULL)
       {
           head=tail=new_node;
       }
       else
       {
           tail->next=new_node;
           tail=new_node;
       }
    size++;
}
void DoublyLinkedList::insert(int i,int n) {
    Node *new_node,*temp;
    int c=0;
    new_node = new Node;
            temp = head;
            while( c!=i)
            {
                c++;
                temp = temp->next;
            }
            
    new_node->data = n;
    new_node->next = temp;
    new_node->prev=temp->prev;
    temp->prev->next=new_node;
    temp->prev=new_node;
            size ++;
             
        }

int DoublyLinkedList::remove(int i) {
    int c=0,d;
   
        if(i==0){
            d=head->data;
            head=head->next;
            head->prev=NULL;
            }
        else if(i==(size-1))
            {
                d=tail->data;
                tail=tail->prev;
                tail->next=NULL;
            }
        else{
            Node* temp = head;
            while(c!=i)
             {
                 temp=temp->next;
                 c++;
             }
             d=temp->data;
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
        }
    size--;
    return d;
}

int DoublyLinkedList::search(int x) {
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

void DoublyLinkedList::concat(DoublyLinkedList b){
    tail->next=b.head;
    b.head->prev=tail;
}


void DoublyLinkedList::display() {
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
    DoublyLinkedList A;
    DoublyLinkedList B;
    do
       {
    std::cout<<"\n1-insert an element in the beginning of the linked list";
    std::cout<<"\n2-insert an element in the ith index of the linked list";
    std::cout<<"\n3-insert an element in the end of the linked list";
    std::cout<<"\n4-remove an element from the beginning of the linked list";
    std::cout<<"\n5-remove an element from the ith index of the linked list";
    std::cout<<"\n6-remove an element from the end of the linked list";
    std::cout<<"\n7-search an element in the linked list";
    std::cout<<"\n8-concat two linked list";
    std::cout<<"\n9-display the linked list\n";
    std::cin>>ch;
 
    switch(ch)
    {
        case '1':
                 std::cout<<"\nEnter element to be inserted";
                 std::cin>>n;
                 A.insert_head(n);
                 break;
        case '2':
                 std::cout<<"\nEnter element and index for insertion";
                 std::cin>>n>>i;
                 A.insert(i, n);
                 break;
        case '3':
                std::cout<<"\nEnter element to be inserted";
                std::cin>>n;
                A.insert_tail(n);
                break;
        case '4':
                std::cout<<A.remove(0);
                std::cout<<"\nElement Removed !\n";
                A.display();
                break;
        case '5':
                std::cout<<"\nEnter index for removal";
                std::cin>>i;
                std::cout<<A.remove(i);
                std::cout<<"\nElement Removed !\n";
                A.display();
                break;
        case '6':
                std::cout<<A.remove(A.size-1);
                std::cout<<"\nElement Removed !\n";
                A.display();
                break;
        case '7':
                std::cout<<"\nEnter element to be searched";
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
                    
                     std::cout<<"\nEnter element to be inserted";
                     std::cin>>n;
                     B.insert_head(n);
                     std::cout<<"\nEnter y if you want to enter more elements n otherwise";
                     std::cin>>choice;
                 }while(choice=='y' || choice=='Y');
                A.concat(B);
                A.display();
                break;
            
        case '9':
                A.display();
                break;
            
    }
    std::cout<<"\nEnter y if you want continue";
                      std::cin>>ch;
    }
    while(ch=='y' || ch=='Y');
    
   return 0;
}
