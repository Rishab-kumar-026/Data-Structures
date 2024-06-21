/*This program is about Queues. A queue is a linear data structure in which insertion of data takes place from one side called Rear
 and deletion of element takes place from other side called as Front. The process of adding elements is called Enqueue and the process
 of deleting elements is called as Dequeue. Queues can be implimented using arrays but the problems is  its static memory allocation.
 Queue follows FIFO(First in First out) order, the first element added gets deleted first.

 consider [40][30][20][10] as a queue. Here the place where 40 is there is called as rear from where insertion or adding is done.
 The place 10 is there is called front from where deletion is done.

 Types of Queues:
 1.Simple Queue means the following program
 2.Circular Queue
 3.Priority Queue
 4.Double ended Queue

  */

#include <iostream>
using namespace std;
#define MAX 10
class Queue
{
public:
    int arr[MAX];
    int rear, front;

    Queue()
    {
        rear = front = -1;
    }

    int insert(int data); // to add element into the queue. Insertion is done through rear. For every insertion rear value increase by one
    int remove();         // to remove element from the queue. Deletion is done through front. For every deletion front value increase by one
    bool is_empty();      // checks queue is empty or not. If rear = front = -1 queue is empty
    bool is_full();       // checks queue is full or not. If rear = array size - 1 then queue is full
    int get_front();      // returns the front element
};

bool Queue::is_empty()
{
    if (rear == front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool Queue::is_full()
{
    if (rear == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int Queue::insert(int data)
{
    if (!is_full())
    {
        ++rear;
        arr[rear] = data;
        cout << data << " inserted to the queue \n";
    }
}

int Queue::remove()
{
    if (!is_empty())
    {
        ++front;
        int element = arr[front];
        cout << element << " removed from the queue \n";
    }
}

int Queue::get_front()
{
    if (rear == front)
    {
        cout << "Queue is empty \n";
    }
    else
    {
        cout << "The front element is : " << arr[++front];
    }
}

int main()
{
    struct Queue rishab_queue;
    rishab_queue.insert(100); // rear = 0
    rishab_queue.insert(200); // rear = 1
    rishab_queue.insert(300); // rear = 2
    rishab_queue.remove();    // front = 0
    rishab_queue.insert(400); // rear = 3
    rishab_queue.insert(500); // rear = 4
    rishab_queue.remove();    // front = 1
    rishab_queue.get_front();
    return 0;
}