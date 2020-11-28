//
//  UpperDiagonal.cpp
//  Data Structure
//
//  Created by Hansika Saxena on 09/09/20.
//  Copyright © 2020 Hansika Saxena. All rights reserved.
//

//Upper diagonal matrix to 1D
#include<iostream>
#include<cmath>
class Diagonal
{  int n,*a;
   public:
       Diagonal(int u)
       {  n=u;
          a=new int [(n*(n+1))/2];
    }
    ~Diagonal()
    { delete [] a;
    }
    void set();
    int get(int i,int j);
 
};
void Diagonal::set()
{
    int e;
    for(int i=1;i<=n;i++)
    {
     for(int j=1;j<=n;j++)
     { std::cout<<"\nEnter element:";
       std::cin>>e;
         if(i<=j)
             a[(i-1)*(n-int((ceil(i/2.0)))+1)+j-i]=e;
         else
         { if(e!=0)
           std::cout<<"\nNon Diagonalonal value should be zero";
         }
     }
    }
    for(int i=0;i<(n*(n+1))/2;i++)
    {
        std::cout<<a[i]<<" ";
    }
}
int Diagonal::get(int i,int j)
{  if(i<=j)
   return  a[(i-1)*(n-int((ceil(i/2.0)))+1)+j-i];
   else
   return 0;
   
}
int main()
{  int s,r,c,val;
   char ch;
   std::cout<<"\nEnter the no. of rows:";
   std::cin>>s;
   if(s<1)
   std::cout<<"\nWrong input";
   else
   
   {
      Diagonal d(s);
       d.set();
       do
       {
          std::cout<<"\nEnter index for the element to be retrieved:";
          std::cin>>r>>c;
          if(r<1 || c<1 || r>s || c>s)
          std::cout<<"\nWrong input!!";
          else
          {  val=d.get(r,c);
              std::cout<<"\nElement at index ("<<r<<","<<c<<"):"<<val;
          }
           std::cout<<"\nDo you wish to enter more(y or n)?:";
           std::cin>>ch;
       }while(ch=='y'||ch=='Y');
   }
       return 0;
   
   
}
