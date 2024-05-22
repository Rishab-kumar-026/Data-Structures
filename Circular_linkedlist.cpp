#include <iostream>
using namespace std;
typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *front, *rear, *temp;

class Circular_linkedList
{
public:
    void create();
    void display();
    void del();
    void search(int element);

    Circular_linkedList()
    {
        front = NULL;
        rear = NULL;
        temp = NULL;
    }
};

void Circular_linkedList::create()
{
    node *newnode;
    newnode = new node;
    cin >> newnode->data;
    newnode->next = NULL;

    if (rear == NULL)
    {
        front = newnode;
        rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
    rear->next = front;
};

void Circular_linkedList::display()
{
    temp = front;

    if (temp == NULL)
    {
        cout << "Circular Linked List is empty \n";
    }
    else
    {
        for (; temp != rear; temp = temp->next)
        { 
            cout << temp->data << "\t";
        }
        cout << temp->data;
    }
};

void Circular_linkedList::del()
{
    temp = front;

    if (temp == NULL)
    {
        cout << "Circular Linked List is empty \n";
    }
    else
    {
        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next; 
            rear->next = front;
            temp->next = NULL;
            delete temp;
        }
    }
};

void Circular_linkedList::search(int element)
{
    temp = front;
    int count = 1;
    if (temp == NULL)
    {
        cout << "Circular Linked List is empty \n";
    }
    else
    {
        for (; temp != rear; temp = temp->next)
        {
            if (temp->data == element)
            {
                cout << element << " found at position " << count << " in the Circular Linked List " << endl;
                 return;
            }
            count++;
 
        }
        if(temp->data == element){
            cout<<element<<" found at position "<<count<<" in the Circular Linked List \n";
            return;
        }
         cout << element << " not found in the Circular Linked List \n";
    }

       
     
};

int main()
{
    Circular_linkedList cll;
    int i, k = 1, value;

    cout << "Enter the total number of Nodes you want to add in the Circular Linked List: ";
    cin >> i;

    while (i)
    {
        cout << "Enter the data of the " << k << " Node: ";
        cll.create();
        i--;
        k++;
    }

    cout << "\nCircular Linked List: ";
    cll.display();

    cout << "\nAfter Deleting the first element of the Circular Linked list: ";
    cll.del();
    cll.display();

    cout << "\nEnter the element you want to search in the Circular Linked List: ";
    cin >> value;

    cll.search(value);

    return 0;
}