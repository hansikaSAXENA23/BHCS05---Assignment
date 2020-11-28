//
//  Program_10.cpp
//  Data Structure
//
//  Created by Hansika Saxena on 20/11/20.
//  Copyright © 2020 Hansika Saxena. All rights reserved.
//

#include<iostream>

using namespace std;

class node
{
    public:
        int data;
        node *next;
        node *prev;
};

class dqueue
{
    node *head,*tail;
 
    public:
    
    dqueue()
    {
        head=NULL;
        tail=NULL;
    }
    
    void insert(int x)
    {
        node *temp;
        int ch;

        if( head == NULL)
        {
            head = new node;
            head->data=x;
            head->next=NULL;
            head->prev=NULL;
            tail=head;
        }
        else
        {
            std::cout <<" Add element 1.FIRST 2.LAST\n Enter Your Choice:\t";
            std::cin >> ch;
            if(ch==1)
            {
                temp=new node;
                temp->data=x;
                temp->next=head;
                temp->prev=NULL;
                head->prev=temp;
                head=temp;
            }
            else
            {
                temp=new node;
                temp->data=x;
                temp->next=NULL;
                temp->prev=tail;
                tail->next=temp;
                tail=temp;
            }
        }
    }
    
    void Delete()
    {
        if(head==0)
        {
            std::cout<<"\nDeQue under flow!!\nNo element to delete";
            return;
        }
        else if(head==tail)
        {
            std::cout<<"\nThe element deleted is:\t"<<head->data;
            head = NULL;
            tail = NULL;
            return;
        }
        int ch;
        std::cout <<"\nDelete 1.First Node 2.Last Node\nEnter Your Choice:\t";
        std::cin>>ch;
        if(ch==1)
        {
            std::cout<<"\nThe element deleted is:\t"<<head->data;
            head=head->next;
            head->prev=NULL;
        }
        else
        {
            std::cout<<"\nThe element deleted is:\t"<<tail->data;
            tail=tail->prev;
            tail->next=NULL;
        }
    }
    
    void display()
    {
        if(head==NULL)
        {
            std::cout <<"\nDeQue is Empty!!\n";
            return ;
        }
        int ch;
        node *temp;
        std::cout <<"\nDisplay From 1.STARTING 2.ENDING\nEnter Your Choice:\t";
        std::cin >>ch;
        std::cout<<"\nElements in DeQue are:\t";
        if (ch==1)
        {
            std::cout<<"head-> ";
            temp=head;
            while(temp!=NULL)
            {
                std::cout << temp->data <<" ";
                temp=temp->next;
            }
        }
        else
        {
            std::cout<<"tail-> ";
            temp=tail;
            while( temp!=NULL)
            {
                std::cout <<temp->data << " ";
                temp=temp->prev;
            }
        }
        std::cout<<"\n";
    }
};

int main()
{
    dqueue d1;
    int ch;
    while (1)
    {
        std::cout<<"DeQue MENU\n1) | INSERT\n2) | DELETE\n3) | DISPLAY\n4) | EXIT\n\nEnter Your Choice:\t";
        std::cin>>ch;
        switch(ch)
        {
            case 1: std::cout<<"\nEnter the Element:\t";
                    std::cin>>ch;
                    d1.insert(ch);
                    std::cout<<"Element inserted successfully!!\n";
                    break;
            case 2: d1.Delete();
                    std::cout<<endl;
                    break;
            case 3: d1.display();
                    break;
            case 4: std::cout<<"\nExiting...\n";
                    exit(1);
            default: std::cout<<"Invalid choice\n";
        }
        std::cout<<endl;
    }
    return 0;
}
