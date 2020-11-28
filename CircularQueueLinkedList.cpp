//
//  CircularQueueLinkedList.cpp
//  Data Structure
//
//  Created by Shreya Saxena on 01/10/20.
//  Copyright © 2020 Shreya Saxena. All rights reserved.
//

// C++ program for insertion and deletion in Circular Queue
#include <iostream>
using namespace std;

// Structure of a Node
class Node {
public:
    int data;
     Node* link;
};

class Queue {
public:
     Node *front, *rear;
};

// Function to create Circular queue
void enQueue(Queue* q, int value)
{
     Node* temp = new Node;
    temp->data = value;
    if (q->front == NULL)
        q->front = temp;
    else
        q->rear->link = temp;

    q->rear = temp;
    q->rear->link = q->front;
}

// Function to delete element from Circular Queue
int deQueue(Queue* q)
{
    if (q->front == NULL) {
        std::cout<<"Queue is empty";
        return INT_MIN;
    }

    // If this is the last node to be deleted
    int value; // Value to be dequeued
    if (q->front == q->rear) {
        value = q->front->data;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    }
    else // There are more than one nodes
    {
         Node* temp = q->front;
        value = temp->data;
        q->front = q->front->link;
        q->rear->link = q->front;
        free(temp);
    }

    return value;
}

// Function displaying the elements of Circular Queue
void displayQueue(class Queue* q)
{
    Node* temp = q->front;
    std::cout<<"\nElements in Circular Queue are: ";
    while (temp->link != q->front) {
        std::cout<< temp->data;
        temp = temp->link;
    }
    std::cout<<temp->data;
}

int main()
{
    // Create a queue and initialize front and rear
    Queue* q = new Queue;
    q->front = q->rear = NULL;

    // Inserting elements in Circular Queue
    std:cout<<"1-enter element \n2-delete element \n3-terminate program"
    enQueue(q, 14);
    enQueue(q, 22);
    enQueue(q, 6);

    // Display elements present in Circular Queue
    displayQueue(q);

    // Deleting elements from Circular Queue
    std::cout<<"\nDeleted value = "<< deQueue(q);
    std::cout<<"\nDeleted value = "<<deQueue(q);

    // Remaining elements in Circular Queue
    displayQueue(q);

    enQueue(q, 9);
    enQueue(q, 20);
    displayQueue(q);

    return 0;
}
