/* Program for Multiple Stacks. We cannot use Single Stacks for storing large amount of data.This is the problem we face in Single stacks
  so to overcome this kind of problem we mainly refer to Multiple Stacks. multiple stack means a single array having two or multiple stacks
  in it. A single array is divided into two stacks.For exam stack one and stack two where we have both top1 and top2 for insertion and
  deletion in both stacks.

  */

#include <iostream>
using namespace std;
class multipleStack
{
public:
    int *arr;
    int len;
    int top1, top2;

    multipleStack(int num)
    {
        len = num; // num is the size of the array
        arr = new int[num];
        top1 = -1;
        top2 = len;
    }

    int push1(int data1); // adding in stack 1
    int push2(int data2); // adding in stack 2
    int print_stack1();   // printing stack 1
    int print_stack2();   // printing stack 2
    int pop1();           // popping last element from stack 1
    int pop2();           // popping last element from stack 2
};

int multipleStack::push1(int data1)
{
    if (top1 < top2 - 1)
    {
        ++top1;
        arr[top1] = data1;
        cout << data1 << " Stored in Stack 1 \n";
    }
    else
    {
        cout << "Stack Overflow \n";
    }
}

int multipleStack::push2(int data2)
{
    if (top1 < top2 - 1)
    {
        top2--;
        arr[top2] = data2;
        cout << data2 << " stored in Stack 2 \n";
    }
    else
    {
        cout << "Stack Overflow \n";
    }
}

int multipleStack::pop1()
{
    if (top1 >= 0)
    {
        int element1 = arr[top1];
        top1--;
        cout << "\n"
             << element1 << " popped out from Stack 1 ";
    }
    else
    {
        cout << "Stack Underflow \n";
    }
}

int multipleStack::pop2()
{
    if (top2 < len)
    {
        int element2 = arr[top2];
        top2++;
        cout << "\n"
             << element2 << " popped out from Stack 2 ";
    }
    else
    {
        cout << "Stack Underflow \n";
    }
}

int multipleStack::print_stack1()
{
    int i;
    for (i = top1; i >= 0; --i)
    {
        cout << arr[i] << " ";
    }
}

int multipleStack::print_stack2()
{
    int i;
    for (i = top2; i < len; ++i)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    struct multipleStack rishab(5);
    // Pushing elements in Stack one
    rishab.push1(10); 
    rishab.push1(20);

    // pushing elements in Stack two
    rishab.push2(100);
    rishab.push2(200);
    rishab.push2(300);

    // checking for stack overflow
    rishab.push1(30);
    rishab.push2(400);

    // printing Stack one
    cout << "Stack one = ";
    rishab.print_stack1();

    // printing Stack two
    cout << "\nStack two = ";
    rishab.print_stack2();

    // removing element from stack one
    rishab.pop1();
    cout << "\nAfter popping stack one = ";
    rishab.print_stack1();

    // removing element from stack two
    rishab.pop2();
    cout << "\nAfter popping stack two = ";
    rishab.print_stack2();

    return 0;
}