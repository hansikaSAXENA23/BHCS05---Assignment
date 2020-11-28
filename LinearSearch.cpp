//
//  LinearSearch.cpp
//  Data Structure
//
//  Created by Shreya Saxena on 31/08/20.
//  Copyright © 2020 Shreya Saxena. All rights reserved.
//

#include<iostream>
class array
{  int *a,n;
   public:
   array(int size)
   { n=size;
     a=new int[n];
   }
   void input(int n);
   int linearsearch(int num);
};

void array::input(int n)
{
    std::cout<<"\nEnter "<<n<<" elements:";
    for(int i=0;i<n;i++)
    {
        std::cin>>a[i];
    }
}
int array::linearsearch(int num)
{  int pos=-1,c=0;
   for(int j=0;j<n;j++)
   if(a[j]==num)
   {  pos=j;
      c++;
      break;
   }
   else c++;
    std::cout<<"\nNo. of comparisons="<<c;
   return pos;
   
}
int main()
{  int s,e,p;
   char ch;
   std::cout<<"\nEnter size of the array=";
   std::cin>>s;
   array A(s);
   A.input(s);
   do
   {
     std::cout<<"\nEnter element to search=";
     std::cin>>e;
     p=A.linearsearch(e);
     if(p==-1)
     std::cout<<"\nElement "<<e<<" not found";
     else
     std::cout<<"\nElement "<<e<<" present at position:"<<p+1;
     std::cout<<"\nDo you want to look for more elements(y or n):";
     std::cin>>ch;
   }while(ch=='y'|| ch=='Y');
   
}
