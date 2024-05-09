#include <iostream>
using namespace std;
struct Node
{
public:
    int data;
    Node *Prev;
    Node *Next;
} *start;

class Doubly_Linked_List
{
public:
    Doubly_Linked_List()
    {
        start = NULL;
    }
    void create(int value);
    void display();
    void add_at_position(int value, int position);
    void deletion(int value);
    void search(int value);
    void sort();
};

void Doubly_Linked_List::create(int value)
{
    Node *temp, *s;
    temp = new (struct Node);
    temp->data = value;
    temp->Next = NULL;

    if (start == NULL)
    {
        temp->Prev = NULL;
        start = temp;
    }
    else
    { // 10 20 30
        s = start;
        while (s->Next != NULL)
        {
            s = s->Next;
        }
        s->Next = temp;
        temp->Prev = s;
    }
}

void Doubly_Linked_List::display()
{
    Node *temp = start;
    if (temp == NULL)
    {
        cout << "Empty Doubly Linked List \n";
    }
    else
    {
        while (temp != NULL)
        {
            cout << temp->data << " <--> ";
            temp = temp->Next;
        }
        cout << "NULL";
        cout << endl;
    }
}

void Doubly_Linked_List::add_at_position(int value, int position)
{
    if (position < 1)
    {
        cout << "Incorrect position \n";
    }
    else if (position == 1)
    {
        Node *temp; //  20 30 40
        temp = new (struct Node);
        temp->data = value;
        temp->Prev = NULL;
        temp->Next = start;
        start->Prev = temp;
        start = temp;
        cout << value << " added at the beginning \n";
    }

    else
    {
        Node *temp = start;
        // 10 20 30 40
        // 10 20 25 30 40
        for (int i = 1; temp != NULL && i < position - 1; i++)
        {
            temp = temp->Next;
        }

        Node *newnode = new (struct Node);
        newnode->data = value;
        newnode->Next = temp->Next;

        if (temp->Next != NULL)
        {
            newnode->Next->Prev = newnode;
        }
        temp->Next = newnode;
        newnode->Prev = temp;

        cout << value << " added at position " << position << " in doubly linked list \n";
    }
}

void Doubly_Linked_List::deletion(int value)
{
    Node *temp, *q;
    // deletion of 1st element
    if (start->data == value)
    {
        temp = start;
        start = start->Next;
        start->Prev = NULL;
        delete temp;
        cout << value << " successfully deleted \n";
    }
    else
    {
        q = start; // 10 20 30 40
        while (q->Next->Next != NULL)
        {
            if (q->Next->data == value)
            {
                temp = q->Next;
                q->Next = temp->Next;
                temp->Next->Prev = q;
                delete temp;
                cout << value << " successfully deleted \n";
            }
            q = q->Next;
        }
            //deletion of last element
        if(q->Next->data == value){
            temp = q->Next;
            q->Next = NULL;
            delete temp;
            cout << value << " successfully deleted \n";
        }
        else{
            cout<<value<<" not found \n";
        }
    }
}

void Doubly_Linked_List::search(int value){
    Node *temp = start;
    int count = 1;
    if(temp == NULL){
        cout<<"Empty Doubly Linked List \n";
    }
    else{
        while(temp != NULL){
            if(temp->data == value){
                cout<<value<<" found at position "<<count;
                return;
            }
            temp = temp->Next;
            count++;
        }
        cout<<value<<" Not found \n";
    }
}

void Doubly_Linked_List::sort(){
    Node *temp = start,*Nxt = NULL;
    int random_variable = 0;
    if(temp == NULL){
        cout<<"Empty Doubly Linked List \n";
    }
    else{
        while(temp->Next != NULL){
            Nxt = temp->Next;
            while(Nxt != NULL){
                if(temp->data > Nxt->data){
                 random_variable = temp->data;
                 temp->data = Nxt->data;
                 Nxt->data = random_variable;
                }
                Nxt = Nxt->Next;
            }
            temp = temp->Next;
        }
    }
}

int main()
{
    int value, position;
    int i, k = 1, element;
    struct Doubly_Linked_List dll;
    cout << "Enter how many elements you want in the Doubly Linked List \n";
    cin >> i;

    while (i)
    {
        cout << "Enter data of " << k << " Node : ";
        cin >> element;
        dll.create(element);
        i--;
        k++;
    }

    cout << "Doubly Linked List : ";
    dll.display();

    cout << "Enter the element to be inserted in the Doubly Linked List :";
    cin >> value;
    cout << "Enter the position \n";
    cin >> position;
    dll.add_at_position(value, position);
    cout << "After insertion the Doubly Linked List :";
    dll.display();

    cout << "Enter the element to be deleted \n";
    cin >> value;
    dll.deletion(value);
    cout << "After deletion the Doubly Linked List :";
    dll.display();

    cout<<"Enter the element to be searched \n";
    cin>>value;
    dll.search(value);
    cout<<endl;

    cout<<"Before sorting Doubly Linked List :";
    dll.display();
    cout<<endl;
    dll.sort();
    cout<<"After sorting Doubly Linked List :";
    dll.display();

    return 0;
}