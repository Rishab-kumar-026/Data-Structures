/*This Program is about Circular queue. Linear or Simple queue is  of a fixed size. We cannot dynamically change the memory size after
initializing. and most of the times we define the size of the array as bigger number but only use a little memory which leads to poor 
utilization of memory. For example we define array size 50 but only add 5 elements in it so we are wasting other 45 elements memory space

Circular queue allows a queue to wrap-around from end to start and helps to reutilize the memory space of elements which have got deleted
For example consider [10][20][30][40][50] is a normal queue and if we delete 10,20 it will be [][][30][40][50] and we cannot add anymore 
elements in it. But in circualar queue [10][20][30][40][50] if we delete 10,20 it will be [][][30][40][50] and now if we want to add any
other element like 60 into the circular queue it will be added like [60][][30][40][50] like this it reutilize the memory space.If you add
70 it will be [60][70][30][40][50].
*/



#include<iostream>
using namespace std;
#define MAX 6
class Circular_queue{
    public:
    int arr[MAX];
    int rear,front;

    Circular_queue(){
        rear = front = MAX-1; //Front & Rear = 5 here
    }
    int add_data(int data);
    int remove_data();
    bool is_empty();
    bool is_full();
};

bool Circular_queue::is_empty(){
    if(front == rear){
        return 1; //Circular queue is Empty if front == rear
    }
    else{
        return 0; //Circular queue is not empty if front != rear
    }
}

bool Circular_queue::is_full(){
    if(front == (rear+1)%MAX){
        return 1;
    }
    else{
        return 0;
    }
}

int Circular_queue::add_data(int data){
    if(!is_full()){
       rear = (rear+1) % MAX;
       arr[rear] = data;
       cout<<data<<" added in the Circular Queue \n";
    }
    else{
        cout<<"Circular Queue is overflow \n";
    }
}

int Circular_queue::remove_data(){
    if(!is_empty()){
        front = (front+1)%MAX;
        int element = arr[front];
        cout<<element<<" removed from Circular Queue \n";
    }
    else{
        cout<<"Circular Queue is Underflow \n";
    }
}

int main(){
    struct Circular_queue rishab_cq;
    rishab_cq.add_data(100); //rear = 0
    rishab_cq.add_data(200); //rear = 1
    rishab_cq.add_data(300); //rear = 2
    rishab_cq.add_data(400); //rear = 3
    rishab_cq.add_data(500); //rear = 4
    
    for(int i=0;i<5;i++){
        cout<<rishab_cq.arr[i]<<" ";
    }
    cout<<endl;
    rishab_cq.remove_data(); //front = 0
    rishab_cq.remove_data(); //front = 1
    rishab_cq.add_data(600); // rear = 0


    return 0;
}