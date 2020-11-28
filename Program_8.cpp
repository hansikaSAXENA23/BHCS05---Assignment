//
//  Program_8.cpp
//  Data Structure
//
//  Created by Hansika Saxena on 20/10/20.
//  Copyright © 2020 Hansika Saxena. All rights reserved.
//

// C++ program for insertion and deletion in Circular Queue
#include<iostream>
using namespace std;

struct Queue
{
    // Initialize front and rear
    int rear, front;

    // Circular Queue
    int size;
    int *arr;

    Queue(int s)
    {
    front = rear = -1;
    size = s;
    arr = new int[s];
    }

    void enQueue(int value);
    int deQueue();
    void displayQueue();
};


/* Function to create Circular queue */
void Queue::enQueue(int value)
{
    if ((front == 0 && rear == size-1) ||
            (rear == (front-1)%(size-1)))
    {
       std::cout<<"\nQueue is Full";
    }

    else if (front == -1) /* Insert First Element */
    {
        front = rear = 0;
        arr[rear] = value;
    }

    else if (rear == size-1 && front != 0)
    {
        rear = 0;
        arr[rear] = value;
    }

    else
    {
        rear++;
        arr[rear] = value;
    }
}

// Function to delete element from Circular Queue
int Queue::deQueue()
{
    if (front == -1)
    {
        std::cout<<"\nQueue is Empty";
        return 0;
    }

    int data = arr[front];
    arr[front] = -1;
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == size-1)
        front = 0;
    else
        front++;

    return data;
}

// Function displaying the elements of Circular Queue
void Queue::displayQueue()
{
    if (front == -1)
    {
        std::cout<<"\nQueue is Empty";
        return;
    }
    std::cout<<"\nElements in Circular Queue are: ";
    if (rear >= front)
    {
        for (int i = front; i <= rear; i++)
            std::cout<<arr[i]<<" ";
    }
    else
    {
        for (int i = front; i < size; i++)
            std::cout<<arr[i]<<" ";

        for (int i = 0; i <= rear; i++)
            std::cout<<arr[i]<<" ";
    }
}

/* Driver of the program */
int main()
{
    int n;
    std::cout<<"\nEnter size of Queue.";
    std::cin>>n;
    Queue Q(n);
    int ch, val;
    std::cout<<"1) Insert Element in Queue"<<endl;
    std::cout<<"2) Delete Element from Queue"<<endl;
    std::cout<<"3) Display Queue"<<endl;
    std::cout<<"4) Exit"<<endl;
    do {
       std::cout<<"Enter choice: "<<endl;
       std::cin>>ch;
       switch(ch) {
          case 1: {
             std::cout<<"Enter value to insert:"<<endl;
             std::cin>>val;
              Q.enQueue(val);
             break;
          }
          case 2: {
              std::cout<<"The deleted element is "<< Q.deQueue() <<endl;
             break;
          }
          case 3: {
              Q.displayQueue();
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
