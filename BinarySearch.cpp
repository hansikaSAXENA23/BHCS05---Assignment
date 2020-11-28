//
//  BinarySearch.cpp
//  Data Structure
//
//  Created by Shreya Saxena on 08/09/20.
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
   void input();
   int binarysearch(int num);
};

void array::input()
{
    std::cout<<"\nEnter "<<n<<" elements:";
    for(int i=0;i<n;i++)
    {
        std::cin>>a[i];
    }
}
int array::binarysearch(int num)
{  int c=0,low=0,high=n-1,mid;
   while (low <= high) {
    mid = (low+high-1)/2;
    c++;
          if (a[mid] == num)
          {
              std::cout<<"\nNo. of comparisons="<<c;
              return mid;
          }
          else if (a[mid] < num)
          {
              low = mid + 1;
          }
          else
          {
              high = mid - 1;
          }
       
      }
    c++;
    std::cout<<"\nNo. of comparisons="<<c;
   return -1;
   
}
int main()
{  int s,e,p;
   char ch;
   std::cout<<"\nEnter size of the array=";
   std::cin>>s;
   array A(s);
   A.input();
   do
   {
     std::cout<<"\nEnter element to search=";
     std::cin>>e;
     p=A.binarysearch(e);
     if(p==-1)
     std::cout<<"\nElement "<<e<<" not found";
     else
     std::cout<<"\nElement "<<e<<" present at position:"<<p+1;
     std::cout<<"\nDo you want to look for more elements(y or n):";
     std::cin>>ch;
   }while(ch=='y'|| ch=='Y');
   
}
