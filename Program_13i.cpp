//
//  Program_13i.cpp
//  Data Structure
//
//  Created by Hansika Saxena on 20/11/20.
//  Copyright © 2020 Hansika Saxena. All rights reserved.
//

//row major | diagonal Matrix

#include<iostream>

using namespace std;

class Matrix
{
    int num;
    int *a;
    public:

    Matrix(int x)
    {
        num = x;
        a = new int [num];
    }
    int getElement(int i, int j)
    {
        if(i==j)
            std::cout<<a[i]<<" ";
        else
            std::cout<<0<<" ";
        return 0;
    }
    void setele(int i, int ele)
    {
        a[i] = ele;
    }
    
    void inputElement();
    void displayElement();
    void searchElement();
};

void Matrix::inputElement()
{
    std::cout<<"Enter the Matrix:\n\n";
    for(int i=0; i<num; i++)
    {
        for(int j=0; j<num; j++)
        {
            int element;
            if(j==i)
            {
                std::cout<<"Enter the element at position ("<<i+1<<","<<j+1<<") :\t";
                cin>>element;
                setele(i,element);
            }
            else
            {
                std::cout<<"Enter the element at position ("<<i+1<<","<<j+1<<") :\t";
                cin>>element;
                while(element!=0)
                {
                    std::cout<<"Element at position ("<<i+1<<","<<j+1<<") can not be non zero!\n";
                    std::cout<<"Enter the element at position ("<<i+1<<","<<j+1<<") :\t";
                    cin>>element;
                }
            }
        }
    }
}

void Matrix::displayElement()
{
    std::cout<<"The Matrix is:\n";
    for(int x=0; x<num; x++)
    {
        for(int y=0; y<num; y++)
        {
            getElement(x,y);
        }
        std::cout<<"\n";
    }
}

void Matrix::searchElement()
{
    int row,column;
    std::cout<<"Enter the index who's element you want to print:\n\n";
    
    std::cout<<"Enter row:\t";
    cin>>row;
    while(row<=0 || row>num)
    {
        std::cout<<"Row has to between 1 and "<<num<<"!\n";
        std::cout<<"Enter row:\t";
        cin>>row;
    }

    std::cout<<"Enter column:\t";
    cin>>column;
    while(column<=0 || column>num)
    {
        std::cout<<"Column has to between 1 and "<<num<<"!\n";
        std::cout<<"Enter column:\t";
        cin>>column;
    }
    
    std::cout<<"\nElement at the given index is:\t";
    getElement(row-1,column-1);
}

int main()
{
    int num;
    std::cout<<"Enter the number of rows and columns in the Matrix:\t";
    cin>>num;
    
    while(num<=0)
    {
        std::cout<<"Number of rows and columns can not be zero!";
        std::cout<<"Enter the number of rows and columns in the Matrix:\t";
        cin>>num;
    }
    
    Matrix M1(num);
    std::cout<<endl;
    M1.inputElement();
    
    int ch;
    
    while(1)
    {
        std::cout<<"\n------------------MENU------------------";
        std::cout<<"\n1) | Display the entered Matrix";
        std::cout<<"\n2) | Display an element at a specific index of Matrix";
        std::cout<<"\n3) | Enter a different Matrix";
        std::cout<<"\n4) | Exit";
        std::cout<<"\n----------------------------------------";
        std::cout<<"\n\nEnter your choice:\t";
        cin>>ch;
        switch(ch)
        {
            case 1: std::cout<<endl;
                    M1.displayElement();
                    break;
            case 2: std::cout<<endl;
                    M1.searchElement();
                    std::cout<<endl;
                    break;
            case 3: {
                    std::cout<<"\nEnter the number of rows and columns in the Matrix:\t";
                    cin>>num;

                    while(num<=0)
                    {
                        std::cout<<"Number of rows and columns can not be zero!\n";
                        std::cout<<"Enter the number of rows and columns in the Matrix:\t";
                        cin>>num;
                    }
                    std::cout<<endl;
                    Matrix M2(num);
                    M1 = M2;
                    M1.inputElement();
                    break;
                    }
            case 4: exit(1);
            default: std::cout<<"\nInvalid choice!!\n";
        }
    }
    
}
