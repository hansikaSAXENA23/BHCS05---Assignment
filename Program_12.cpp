//
//  Program_12.cpp
//  Data Structure
//
//  Created by Hansika Saxena on 20/11/20.
//  Copyright © 2020 Hansika Saxena. All rights reserved.
//

#include<iostream>

using namespace std;

template <class T>
class sorting
{
    T *a;
    int num;
    int counter,swap_val;
    public:
    sorting(int x)
    {
        num = x;
        a = new T [num];
    }
    
    void get_item()
    {
        for(int i=0;i<num;i++)
        {
            std::cout<<"\n a["<<i+1<<"] = ";
            std::cin>>a[i];
        }
    }

    void selectionSort()
    {
        T temp;
        counter = 0;
        swap_val = 0;
        for(int i=0;i<num;i++)
        {
            for(int j=i+1;j<num;j++)
            {
                if(a[i]>a[j])
                {
                    temp=a[i];
                    a[i]=a[j];
                    a[j]=temp;
                    swap_val++;
                }
                counter++;
                std::cout<<"\nThe array after "<<counter<<" comparison:\n";
                display();
            }
        }
        std::cout<<"\nTotal number of comparisons:\t"<<counter;
        std::cout<<"\nTotal number of swaps:\t"<<swap_val;
        std::cout<<"\nSorted array:\n";
        display();
    }

    void bubbleSort()
    {
        T temp;
        counter = 0;
        swap_val = 0;
        for(int i=0;i<num;i++)
        {
            for(int j=0;j<num-i-1;j++)
            {
                if(a[j]>a[j+1])
                {
                    temp=a[j];
                    a[j]=a[j+1];
                    a[j+1]=temp;
                    swap_val++;
                }
                counter++;
                std::cout<<"\nThe array after "<<counter<<" comparison:\n";
                display();
            }
        }
        std::cout<<"\nTotal number of comparisons:\t"<<counter;
        std::cout<<"\nTotal number of swaps:\t"<<swap_val;
        std::cout<<"\nSorted array:\n";
        display();
    }

    void insertionSort()
    {
        T tmp;
        counter = 0;
        swap_val = 0;
        int j;
        for(int i=1;i<num;i++)
        {
            tmp=a[i];
            j=i-1;
            while(j>= 0 && a[j]>tmp)
            {
                a[j+1]=a[j];
                j--;
                swap_val++;
            }
            a[j+1]=tmp;
            counter++;
            std::cout<<"\nThe array after "<<counter<<" comparison:\n";
            display();
        }
        std::cout<<"\nTotal number of comparisons:\t"<<counter;
        std::cout<<"\nTotal number of swaps:\t"<<swap_val;
        std::cout<<"\nSorted array:\n";
        display();
    }

    void display()
    {
        for(int i=0;i<num;i++)
        {
            std::cout<<" "<<a[i]<<", ";
        }
        std::cout<<"\n\n";
    }

};// End of Class


int main()
{
    int num;
    std::cout<<"Enter the number of elements in the array:\t";
    std::cin>>num;
    sorting<int> A(num);
    std::cout<<"Enter an integer array:\n";
    A.get_item();
    std::cout<<"\nThe entered array is:\n";
    A.display();
    int ch;
       do
    {
           std::cout<<"-----------MENU-----------\n";
           std::cout<<"1) | Insertion Sort\n";
           std::cout<<"2) | Bubble Sort\n";
           std::cout<<"3) | Selection Sort\n";
           std::cout<<"4) | Exit\n";
           std::cout<<"--------------------------\n";
          std::cout<<"\nEnter your choice:\t";
          std::cin>>ch;
          switch (ch)
        {
             case 1: std::cout<<endl;
                     A.insertionSort();
                     exit(0);
                     break;
             case 2: std::cout<<endl;
                     A.bubbleSort();
                     exit(0);
                     break;
             case 3: std::cout<<endl;
                     A.selectionSort();
                     exit(0);
                     break;
             case 4: std::cout<<"\nExiting..."<<endl;
                     break;
             default: std::cout<<"Invalid choice"<<endl;
          }
        std::cout<<endl;
       } while(ch!=4);

}
