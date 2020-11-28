//
//  Program_13ii.cpp
//  Data Structure
//
//  Created by Hansika Saxena on 20/11/20.
//  Copyright © 2020 Hansika Saxena. All rights reserved.
//

//row major | lower triangular Matrix

#include<iostream>

using namespace std;

class Matrix
{
    int num;
    int *a;
    int n;
    
    public:
        
    Matrix(int x)
    {
        int num = (x*(x+1))/2;
        a = new int [num];
        n = x;
    }
    
    int getElement(int i, int j)
    {
        if(j<=i)
            cout<<a[(i*(i+1))/2+j]<<" ";
        else
            cout<<0<<" ";
        return 0;
    }
    
    void setele(int i, int j, int ele)
    {
        a[(i*(i+1))/2+j] = ele;
    }
    
    void inputElement();
    void displayElement();
    void searchElement();
    
};

void Matrix::inputElement()
{
    cout<<"Enter the Matrix:\n\n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int element;
            if(j<=i)
            {
                cout<<"Enter the element at position ("<<i+1<<","<<j+1<<") :\t";
                cin>>element;
                setele(i,j,element);
            }
            else
            {
                cout<<"Enter the element at position ("<<i+1<<","<<j+1<<") :\t";
                cin>>element;
                while(element!=0)
                {
                    cout<<"Element at position ("<<i+1<<","<<j+1<<") can not be non zero!\n";
                    cout<<"Enter the element at position ("<<i+1<<","<<j+1<<") :\t";
                    cin>>element;
                }
            }
        }
    }
}

void Matrix::displayElement()
{
    cout<<"The Matrix is:\n";
    for(int x=0; x<n; x++)
    {
        for(int y=0; y<n; y++)
        {
            getElement(x,y);
        }
        cout<<"\n";
    }
}

void Matrix::searchElement()
{
    int row,column;
    cout<<"Enter the index who's element you want to print:\n\n";
    
    cout<<"Enter row:\t";
    cin>>row;
    while(row<=0 || row>n)
    {
        cout<<"Row has to between 1 and "<<n<<"!\n";
        cout<<"Enter row:\t";
        cin>>row;
    }
    
    cout<<"Enter column:\t";
    cin>>column;
    while(column<=0 || column>n)
    {
        cout<<"Column has to between 1 and "<<n<<"!\n";
        cout<<"Enter column:\t";
        cin>>column;
    }

    cout<<"\nElement at the given index is:\t";
    getElement(row-1,column-1);
}

int main()
{
    int num;
    cout<<"Enter the number of rows and columns in the Matrix:\t";
    cin>>num;

    while(num<=0)
    {
        cout<<"Number of rows and columns can not be zero!\n";
        cout<<"Enter the number of rows and columns in the Matrix:\t";
        cin>>num;
    }

    Matrix M1(num);
    cout<<endl;
    M1.inputElement();
    
    int ch;
    
    while(1)
    {
        cout<<"\n------------------MENU------------------";
        cout<<"\n1) | Display the entered Matrix";
        cout<<"\n2) | Display an element at a specific index of Matrix";
        cout<<"\n3) | Enter a different Matrix";
        cout<<"\n4) | Exit";
        cout<<"\n----------------------------------------";
        cout<<"\n\nEnter your choice:\t";
        cin>>ch;
        switch(ch)
        {
            case 1: cout<<endl;
                    M1.displayElement();
                    break;
            case 2: cout<<endl;
                    M1.searchElement();
                    cout<<endl;
                    break;
            case 3: {
                    cout<<"\nEnter the number of rows and columns in the Matrix:\t";
                    cin>>num;

                    while(num<=0)
                    {
                        cout<<"Number of rows and columns can not be zero!\n";
                        cout<<"Enter the number of rows and columns in the Matrix:\t";
                        cin>>num;
                    }
                    cout<<endl;
                    Matrix M2(num);
                    M1 = M2;
                    M1.inputElement();
                    break;
                    }
            case 4: exit(1);
            default: cout<<"\nInvalid choice!!\n";
        }
    }
    
}
