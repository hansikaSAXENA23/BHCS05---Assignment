//
//  Program_9.cpp
//  Data Structure
//
//  Created by Hansika Saxena on 20/11/20.
//  Copyright © 2020 Hansika Saxena. All rights reserved.
//

#include <iostream>

using namespace std;

class Node
{
    public:
        int data;
        struct Node* next;
};

class Queue
{
    struct Node *front, *rear;
    public:
        Queue()
        {
            front = NULL;
            rear = NULL;
        }
        void enQueue(int value);
        void deQueue();
        void displayQueue();
};

void Queue::enQueue(int value)
{
    Node* temp = new Node;
    temp->data = value;
    if(front == NULL)
        front = temp;
    else
        rear->next = temp;

    rear = temp;
    rear->next = front;
}

void Queue::deQueue()
{
    if(front == NULL)
    {
        std::cout<<"Queue is empty!!\nNo element to delete.";
        return;
    }

    int value;
    if(front == rear)
    {
        value = front->data;
        front = NULL;
        rear = NULL;
    }
    else
    {
        Node* temp = front;
        value = temp->data;
        front = front->next;
        rear->next = front;
        delete temp;
    }

    std::cout<<"The element deleted is:\t"<<value<<"\n";
}

void Queue::displayQueue()
{
    Node* temp = front;
    std::cout<<"Elements in Circular Queue are:\nfront->";
    while (temp->next != front) {
        std::cout<<temp->data<<" ";
        temp = temp->next;
    }
    std::cout<<temp->data<<"\n";
}

int main()
{
    Queue q;
    int ch;
       do
    {
           std::cout<<"--------------MENU--------------\n";
           std::cout<<"1) | Insert element to the queue\n";
           std::cout<<"2) | Delete element from the queue\n";
           std::cout<<"3) | Display all the elements of the queue\n";
           std::cout<<"4) | Exit\n";
           std::cout<<"--------------------------------\n";
          std::cout<<"\nEnter your choice:\t";
          std::cin>>ch;
          int ele;
          switch (ch)
        {
             case 1: std::cout<<endl;
                     std::cout<<"Enter the element you want to insert in the queue:\t";
                     std::cin>>ele;
                     q.enQueue(ele);
                     std::cout<<"Element inserted successfully!"<<endl;
                     break;
             case 2: std::cout<<endl;
                     q.deQueue();
                     break;
             case 3: std::cout<<endl;
                     q.displayQueue();
                     break;
             case 4: std::cout<<"\nExiting..."<<endl;
                     break;
             default: std::cout<<"Invalid choice"<<endl;
          }
        std::cout<<endl;
       } while(ch!=4);

    return 0;
}
