//
//  ColumnMajor.cpp
//  Data Structure
//
//  Created by Hansika Saxena on 08/09/20.
//  Copyright © 2020 Hansika Saxena. All rights reserved.
//

//converting 2D array to 1D using column-major formula
#include<iostream>

class array2D
{   public:
    int row,col;
    int *a;
    array2D(int r,int c)
    { row=r;
      col=c;
      a=new int[row*col];
    }
    ~array2D()
    { delete [] a;
    }
    void set();
    int get(int i,int j);
};
void array2D::set()
{  int p;
    std::cout<<"\nEnter elements:";
    for(int i=1;i<=row;i++)
    {
     for(int j=1;j<=col;j++)
     {
       p=(i-1)+(j-1)*col;
       std::cin>>a[p];
     }
    }
    for(int i=0;i<=p;i++)
    {
        std::cout<<a[i];
    }
}
int array2D::get(int i,int j)
{  int p=(i-1)+(j-1)*col;
   return a[p];
}
int main()
{  int r,c,val;
   std::cout<<"\nEnter no. of rows and columns for the array:";
   std::cin>>r>>c;
   if(r<1 || c<1 )
   std::cout<<"\nWrong set!!";
   else
   {  array2D M(r,c);
       M.set();
       std::cout<<"\nEnter positions for the element to be retrieved:";
       std::cin>>r>>c;
       if(r<1 || c<1 || r>M.row || c>M.col)
       std::cout<<"\nWrong set!!";
       else
       {  val=M.get(r,c);
          std::cout<<"\nElement at index ("<<r<<","<<c<<"):"<<val;
       }
       
    
    }
       
    return 0;
   
   
}
