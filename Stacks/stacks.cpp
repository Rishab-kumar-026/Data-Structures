/*  This program is about Stacks.Stacks is a linear data structure in which insertion and deletion of elements can
 be only perfomed by one side that is called as Top.Stack consider LIFO(Last in First Out ) order,the element which added at last will
 be the first to be removed or FILO(First in Last Out) order ,the first element is removed at last.Stacks can be implemented using arrays and
 linked lists but mostly they are implemented using single dimension arrays. The only problem with arrays is its static memory allocation
 which can be changed after assinging.

 Real time example like deck of cards, arrangement of plates etc */

#include <iostream>
using namespace std;
#define MAX 5 // Defining the size of our stack
class Stack
{
public:
    int top;
    int arr[MAX];

    Stack()
    {
        top = -1;
    }
    int push(int data); // Adding data into the stack.For every adding top value increase by one
    int pop();          // Removing data from stack. For deletion top value decrease by one from 2nd time
    int is_empty();     // check stack is empty or not
    int is_full();      // check stack is full or not
};

int Stack::push(int data)
{
    if (top >= MAX)
    {
        cout << "Stack Overrflow \n";
    }
    else
    {

        arr[++top] = data;
        cout << data << " stored in the stack \n";
    }
}

int Stack::pop()
{
    if (top < 0)
    {
        cout << "Stack Underflow \n";
    }
    else
    {

        int element = arr[top--];
        cout << element << " removed from the stack \n";
    }
}

int Stack::is_empty()
{
    if (top == -1)
    {
        cout << "Stack is Empty \n";
    }
}

int Stack::is_full()
{
    if (top >= MAX - 1)
    {
        cout << "Stack is Full \n";
    }
}

int main()
{
    struct Stack rishab_stack; // Assinging rishab_stack as a variable to Class Stack
    rishab_stack.push(10); //top = 0
    rishab_stack.push(20); //top = 1
    rishab_stack.push(30); //top = 2
    rishab_stack.push(40); //top = 3
    rishab_stack.push(50); //top = 4
    rishab_stack.pop(); //top = 4
    rishab_stack.pop(); //top = 3

    cout << "Top element in the stack is " << rishab_stack.arr[rishab_stack.top];
    return 0;
}