//
//  Program_15.cpp
//  Data Structure
//
//  Created by Hansika Saxena on 20/11/20.
//  Copyright © 2020 Hansika Saxena. All rights reserved.
//

// C++ code to implement priority-queue using array implementation of binary max heap
#include <iostream>
using namespace std;
class priority_queue
{
int H[50];
int size;
public:
    priority_queue()
    {
        size=-1;
    }
int parent(int i)
{
return (i - 1)/2;
}
int leftChild(int i)
{
return ((2 * i) + 1);
}
int rightChild(int i)
{
return ((2 * i) + 2);
}
//------- Function to shift up the node in order to maintain the heap property------
void shiftUp(int i)
{
while (i>0 && H[parent(i)] < H[i])
{
swap(H[parent(i)], H[i]);  // Swap parent and current node
i = parent(i);  // Update i to parent of i
}
}
//-------- Function to shift down the node in order to maintain the heap property-----
void shiftDown(int i)
{
int maxIndex = i;
// Left Child
int l = leftChild(i);
if (l <= size && H[l] > H[maxIndex])
maxIndex = l;
// Right Child
int r = rightChild(i);
if (r <= size && H[r] > H[maxIndex])
maxIndex = r;
// If i not same as maxIndex
if (i != maxIndex)
{
swap(H[i], H[maxIndex]);
shiftDown(maxIndex);
}
}
// ------------Function to insert a new element in the Binary Heap-------------
void insert(int p)
{
size = size + 1;
H[size] = p;
shiftUp(size);  // Shift Up to maintain heap property
}
//--------- Function to extract the element with maximum priority---------
int extractMax()
{
int result = H[0];
// Replace the value at the root with the last leaf
H[0] = H[size];
size = size - 1;
shiftDown(0);  // Shift down the replaced element to maintain the heap property
return result;
}
//-----------Function to get value of the current maximum element----------
int getMax()
{
return H[0];
}
//------Function to display the priority queue-----
int display()
{
 int i = 0;
cout<<"PRIORITY QUEUE : ";
while (i <= size)
{
cout<<H[i]<<" ";
i++;
}
    return 0;
}
};
// Driver Code
int main()
{

priority_queue pq;
int n,c,s,max;
char ch;
cout<<"\n<----PRIORITY QUEUE----->\n";
cout<<"Enter how many elements you want in your priority queue : ";
cin>>s;
cout<<"Enter the elements : ";
for(int i=0;i<s;i++)
{
    cin>>n;
    pq.insert(n);
}
pq.display();
do{
  cout<<"What do you want??"
      <<"\n 1. extract maximum from the priority queue"
      <<"\n 2. Display the maximum element from the queue"
      <<"\n 3.exit";
      cout<<"\n Enter our choice : \n";
      cin>>c;
    switch(c)
    {
        case 1: cout<<"Extracted Node is : "
                    <<pq.extractMax()<<"\n";
                cout<<"AFTER EXTRACTION \n";
                pq.display();
                    break;
        case 2: cout<<"Node with maximum priority : ";
                max=pq.getMax();
                cout<<max;
                    break;
        case 3: cout<<"\n TERMINATING....";
                exit(0);
                break;
    }
    cout<<"\n Do you wish to coninue??";
    cin>>ch;
}while(ch=='y'||ch=='Y');

return 0;
}
