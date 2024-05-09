/*Linked List is another type of data structure. The memory space for elements are allocated dynamically.In linked list
we have node and reference to the next node called as link. The first node is called as HEAD and last one is called as Tail.
Linked list are completely differenet from Arrays.Insertion  and deletion of elements is very much easy in linked list.

Types of Linked List:      
1.Singly Linked List
2.Doubly Linked List

The following is the example of Singly Linked List
                                 HEAD                                                TAIL
Example of Singly Linked List : [Node][link] --> [Node][link] --> [Node][link] --> [Node][NULL]
                                  [10][1A2C] -->[20][1B2C] -->[30][1C2C] -->[40][NULL]
*/

#include <iostream>
using namespace std;
class Node // Class For Node
{
public:
    int data;
    Node *link;
};

class Linked_List // Class for Linked List
{
public:
    Node *Head, *Tail; // we have a head and tail in linked list
    Linked_List()
    {
        Head = NULL; // if head = null then linked list is empty
    }
    void Create_LL();
    void Display_LL();
    Node *Get_Node();
    void Append_Node(Node *NewNode);
    void Insert_at_position(Node *NewNode, int position);
    void Deleting_Node(int position);
    void Searching_Node(int value);
    void Sorting_Linked_List();
};

void Linked_List::Create_LL()
{
    char answer;
    Node *NewNode;
    while (true)
    {
        cout << "Do you want to add any Node (Y/N) \n";
        cin >> answer;
        if (answer == 'n')
        {
            break;
        }
        NewNode = Get_Node();
        Append_Node(NewNode);
    }
}

Node *Linked_List::Get_Node()
{
    Node *NewNode;
    NewNode = new Node;
    cout << "Enter the data of the New Node \n";
    cin >> NewNode->data;
    NewNode->link = NULL;
    return (NewNode);
}

void Linked_List::Append_Node(Node *NewNode)
{
    if (Head == NULL)
    {
        Head = NewNode;
        Tail = NewNode;
    }
    else
    {
        Tail->link = NewNode;
        Tail = NewNode;
    }
}

void Linked_List::Display_LL()
{
    Node *temp = Head;
    if (temp == NULL)
    {
        cout << "Linked List is empty \n";
    }
    else
    {
        while (temp != NULL)
        {
            cout << temp->data << "\t";
            temp = temp->link;
        }
        cout << endl;
    }
}

void Linked_List::Insert_at_position(Node *NewNode, int position)
{
    Node *temp = Head;
    int count = 1;
    int flag = 1;
    if (position == 1)
    {
        NewNode->link = temp;
        Head = NewNode;
    }
    else
    {
        while (count != position - 1)
        {
            temp = temp->link;
            if (temp == NULL)
            {
                flag = 0;
                break;
            }
            count++;
        }

        if (flag == 1)
        {
            NewNode->link = temp->link;
            temp->link = NewNode;
        }
        else
        {
            cout << "Position Not found in the Linked List \n";
        }
    }
}

void Linked_List::Deleting_Node(int position)
{
    Node *curr_element, *temp = Head;
    int count = 1, flag = 1;
    if (position == 1)
    {
        Head = Head->link;
        delete temp;
    }
    else
    {
        while (count != position - 1)
        {
            temp = temp->link;
            if (temp == NULL)
            {
                flag = 0;
                break;
            }
            count++;
        }
        if (flag == 1)
        {
            curr_element = temp->link;
            temp->link = curr_element->link;
            delete curr_element;
        }
        else
        {
            cout << "Position not found to be deleted \n";
        }
    }
}

void Linked_List::Searching_Node(int value)
{
    Node *temp = Head;
    int count = 1;
    if (temp == NULL)
    {
        cout << "Linked List is empty \n";
    }
    else
    {
        while (temp != NULL)
        {
            if (temp->data == value)
            {
                cout << value << " found at position " << count << " in the Linked List \n";
                return;
            }
            temp = temp->link;
            count++;
        }
        cout << value << " not found in the Linked List \n";
    }
}

void Linked_List::Sorting_Linked_List()
{
    Node *temp = Head, *Next = NULL;
    int data = 0;
    if (temp == NULL)
    {
        cout << "Linked List is empty \n";
    }
    else
    {
        while (temp->link != NULL)
        {
            Next = temp->link;
            while (Next != NULL)
            {
                if (temp->data > Next->data)
                {
                    data = temp->data;
                    temp->data = Next->data;
                    Next->data = data;
                }
                Next = Next->link;
            }
            temp = temp->link;
        }
    }
}

int main()
{
    int position;
    int value;
    struct Linked_List LL;
    LL.Create_LL();
    LL.Display_LL();
    struct Node *NewNode;
    NewNode = LL.Get_Node();
    cout << "Enter the position where you want it to be inserted \n";
    cin >> position;
    LL.Insert_at_position(NewNode, position);
    cout << "Linked List after inserting a new element \n";
    LL.Display_LL();
    cout << "Enter the position of element you want to delete from Linked List \n";
    cin >> position;
    LL.Deleting_Node(position);
    cout << "Linked List after deleting the specified element \n";
    LL.Display_LL();
    cout << "Enter the element you want to search in the Linked List \n";
    cin >> value;
    LL.Searching_Node(value);
    cout << "Before sorting Linked List was : \n";
    LL.Display_LL();
    LL.Sorting_Linked_List();
    cout << "After sorting Linked List is : \n";
    LL.Display_LL();

    return 0;
}
