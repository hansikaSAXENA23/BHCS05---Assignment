//
//  Diagonal.cpp
//  Data Structure
//
//  Created by Shreya Saxena on 09/09/20.
//  Copyright © 2020 Shreya Saxena. All rights reserved.
//

//diagonal matrix to 1D
#include<iostream>

class Diagonal
{  int n,*a;
   public:
       Diagonal(int u)
       {  n=u;
          a=new int [n];
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
          for(int j=1;j<=n;j++)
          { std::cout<<"\nEnter element:";
            std::cin>>e;
           if(i==j)
            a[i-1]=e;
            else
            { if(e!=0)
              std::cout<<"\nNon diagonal value should be zero";
            }
          }
}
int Diagonal::get(int i,int j)
{  if(i==j)
   return a[i-1];
   else
   return 0;

}
int main()
{  int s,r,c,val;
   std::cout<<"\nEnter the no. of rows:";
   std::cin>>s;
   if(s<1)
   std::cout<<"\nWrong input";
   else

   {
      Diagonal d(s);

       std::cout<<"\nEnter index for the element to be retrieved:";
       std::cin>>r>>c;
        if(r<1 || c<1 || r>s || c>s)
        std::cout<<"\nWrong input!!";
        else
        {  val=d.get(r,c);
           std::cout<<"\nElement at index ("<<r<<","<<c<<"):"<<val;
        }
   }
       return 0;


}
