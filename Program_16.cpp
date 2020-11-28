//
//  Program_16.cpp
//  Data Structure
//
//  Created by Hansika Saxena on 20/11/20.
//  Copyright © 2020 Hansika Saxena. All rights reserved.
//

//postfix using stack
#include <iostream>
#include <cstring>

using namespace std;

class node
{
    public:
        int data;
        node *next;
};

class postfix
{
    node *p, *top, *temp, *ptr;
    
    public:
    
    postfix()
    {
        p = NULL; top = NULL; temp = NULL;
    }

    void pushElement(int x)
    {
        p = new node;
        p->data = x;
        p->next = NULL;
        
        if (top == NULL)
        {
            top = p;
        }

        else
        {
               temp = top;
            top = p;
            p->next = temp;
        }
    }

    char popElement()
    {
           if (top == NULL)
        {
               cout<<"Underflow!!";
        }

        else
        {
            ptr = top;
            top = top->next;
            return(ptr->data);
            delete ptr;
        }
        return 0;
    }
};

int main()
{
    postfix p;
    char x[30];
    int a, b;
    cout<<"Enter the balanced postfix expression:\n";
    cin>>x;
    for (int i = 0; i < strlen(x); i++)
    {
        if (x[i] >= 48 && x[i] <= 57)
            p.pushElement(x[i]-'0');
        else if (x[i] >= 42 && x[i] <= 47)
        {
            b=p.popElement();
            a=p.popElement();
            switch(x[i])
            {
                case '+':
                p.pushElement(a+b);
                break;

                   case '-':
                p.pushElement(a-b);
                break;

                case '*':
                p.pushElement(a*b);
                break;

                case '/':
                p.pushElement(a/b);
                break;
            }
        }
    }
    int ans = p.popElement();
    cout<<"Answer is:\t"<<ans<<endl;

}
