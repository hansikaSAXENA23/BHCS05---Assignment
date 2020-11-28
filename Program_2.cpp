//
//  Program_1.cpp
//  Data Structure
//
//  Created by Hansika Saxena on 01/10/20.
//  Copyright © 2020 Hansika Saxena. All rights reserved.
//

#include <iostream>
using namespace std;
class Search
{
public: int *A,n;
    Search(int x)
    {
        n=x;
        A=new int[n];
    }
    void input();
    int binarySearch(int e);
};

//Function to input n elements to the Array
void Search::input(){
    for(int i=0;i<n;i++)
    {
        std::cin>>A[i];
    }
}
//Function to search the element
int Search::binarySearch(int e){
   int low=0,high=n-1,mid;
    while (low <= high) {
     mid = (low+high-1)/2;
           if (A[mid] == e)
           {
               return mid;
           }
           else if (A[mid] < e)
           {
               low = mid + 1;
           }
           else
           {
               high = mid - 1;
           }
        
       }
    return -1;
}

//Execution begins here
int main()
{
    int n;
    std::cout<<"Enter no. of elements:\n";
    std::cin>>n;
    Search S(n);
    std::cout<<"Enter the elements:\n";
    S.input();
    std::cout<<"Enter the element to be searched:\n";
    std::cin>>n;
    std::cout<<S.binarySearch(n);
    
    return 0;
}
