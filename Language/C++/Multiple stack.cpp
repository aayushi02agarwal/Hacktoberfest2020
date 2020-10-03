//Program for multiple stack
//While implementing a stack using an array,the size of the array must be known in
//advance. If the stack is allocated less space, then frequent OVERFLOW conditions will be encountered.
//To deal with this problem, the code will have to be modified to reallocate more space for the array.
//In case we allocate a large amount of space for the stack, it may result in sheer wastage of
//memory. Thus, there lies a trade-off between the frequency of overflows and the space allocated.
//So, a better solution to deal with this problem is to have multiple stacks or to have more than
//one stack in the same array of sufficient size.
#include<iostream>
using namespace std;

class twostacks
{
    int *arr;
    int size;
    int top1;
    int top2;

 public:
     twostacks(int n)
     {
       size=n;
       arr=new int[n];
       top1=-1;
       top2=size;
     }

     void push1(int val)
     {
         if(top1<top2-1)
         {
             top1++;
             arr[top1]= val;
         }
         else
         {
             cout<<"Stackoverflow"<<endl;
             exit(1);
         }
     }

     void push2(int val)
     {
         if(top1<top2-1)
         {
             top2--;
             arr[top2]=val;
         }
         else
         {
             cout<<"Stackoverflow"<<endl;
             exit(1);
         }
     }

     int pop1()
     {
         if(top1>=0)
         {
             int x;
             x=arr[top1];
             top1--;
             return x;
         }
         else
         {
             cout<<"Stackunderflow"<<endl;
             exit(1);
         }
     }

     int pop2()
     {
         if(top2<size)
         {
             int x;
             x=arr[top2];
             top2++;
             return x;
         }
         else
         {
             cout<<"Stackunderflow"<<endl;
             exit(1);
         }
     }

     void display1()
     {
         if(top1==-1)
         {
             cout<<"Stack is empty"<<endl;
         }
         else
         {
             for(int i=top1;i>=0;i--)
             {
                 cout<<arr[i]<<endl;
             }
         }
     }

     void display2()
     {
         if(top2==size)
         {
             cout<<"Stack is empty"<<endl;
         }
         else
         {
             for(int i=top2;i<size;i++)
             {
                 cout<<arr[i]<<endl;
             }
         }
     }
};

int main()
{
    twostacks ts(6);
    ts.push1(0);
    ts.push1(1);
    ts.push1(2);
    ts.push2(3);
    ts.push2(4);
    ts.push2(5);
    cout<<"Stack 1:"<<endl;
    ts.display1();
    cout<<endl;
    cout<<"Stack 2:"<<endl;
    ts.display2();
    cout<<"\n Popped value is"<<ts.pop1()<<endl;
    cout<<"Stack 1:"<<endl;
    ts.display1();
    cout<<"\n Popped value is"<<ts.pop2()<<endl;
    cout<<"Stack 2:"<<endl;
    ts.display2();
    return 0;
}
