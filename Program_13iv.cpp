//
//  Program_13iv.cpp
//  Data Structure
//
//  Created by Hansika Saxena on 20/11/20.
//  Copyright © 2020 Hansika Saxena. All rights reserved.
//

//row major | symmetric Matrix

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
    
    int getele(int i, int j)
    {
        if(i<=j)
            cout<<a[(n*i)+j-((i*(i+1))/2)]<<" ";
        else
            cout<<a[j*n-(j-1)*j/2+i-j]<<" ";
    }
    
    void setele(int i, int j, int ele)
    {
        a[(n*i)+j-((i*(i+1))/2)] = ele;
    }
    
    void input();
    void display();
    void search();
    
};

void Matrix::input()
{
    cout<<"Enter the Matrix:\n\n";
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int element;
            if(i<=j)
            {
                cout<<"Enter the element at position ("<<i+1<<","<<j+1<<") :\t";
                cin>>element;
                setele(i,j,element);
            }
            else
            {
                cout<<"Enter the element at position ("<<i+1<<","<<j+1<<") :\t";
                cin>>element;
                while(element!=a[(n*j)+i-((j*(j+1))/2)])
                {
                    cout<<"Element at position ("<<i+1<<","<<j+1<<") should be equal to element at position ("<<j+1<<","<<i+1<<")\n";
                    cout<<"Enter the element at position ("<<i+1<<","<<j+1<<") :\t";
                    cin>>element;
                }
            }
        }
    }
}

void Matrix::display()
{
    cout<<"The Matrix is:\n";
    for(int x=0; x<n; x++)
    {
        for(int y=0; y<n; y++)
        {
            getele(x,y);
        }
        cout<<"\n";
    }
}

void Matrix::search()
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
    getele(row-1,column-1);
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
    M1.input();
    
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
                    M1.display();
                    break;
            case 2: cout<<endl;
                    M1.search();
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
                    M1.input();
                    break;
                    }
            case 4: exit(1);
            default: cout<<"\nInvalid choice!!\n";
        }
    }
    
}
