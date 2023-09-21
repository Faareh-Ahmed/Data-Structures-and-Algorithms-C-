/*
    Doubly Linked List
    Node has prev address and next Node address
    
*/

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data; // store integar data of the node
        this->next = NULL; // pointer to next node in the list
        this->prev = NULL; // pointer to previous Node in the List
    }
};

void printNodes(Node *&head)
{
    Node *temp = head;
    cout << endl;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void getLength(Node *&head)
{
    int length = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        length++;
    }
    cout << endl
         << "Length Of the Linked List: " << length << endl;
}

void insertAtHead(int data, Node *&head)
{
    cout << endl
         << "Inserting " << data << " at head" << endl;
    Node *temp = new Node(data); // creating new node set its data
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertAtTail(int data, Node *&head, Node *&tail)
{
    cout << endl
         << "Inserting " << data << " at Tail" << endl;
    Node *temp = new Node(data); // creating new node set its data
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(int position, int data, Node *&head, Node *&tail)
{
    cout << "\n Inserting at Position: " << position << endl;
    Node *temp = head; // creating temp Node that initially starts with head position and will point to previous Node of the New Node
    if (position == 1) // Inserting at head Position
    {
        insertAtHead(data, head);
        return;
    }
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL) // Check if the previous node is the last node then insert at Tail
    {
        insertAtTail(data, head, tail);
        return;
    }

    Node *newnode = new Node(data); // Creating new Node to place the data
    Node *afternode = temp->next;
    temp->next = newnode; // Previous Node pointing to the New node
    newnode->prev = temp;
    newnode->next = afternode;
    afternode->prev = newnode;
}

void deleteNodeByPosition(int position, Node * &head,Node* &tail)
{
    cout << endl
         << "Deleting at Position: " << position << endl;

    if (position == 1) // We want to delete the First Node
    {
        Node *current = head; // temp Node that points to head
        head=current->next;
        head->prev=NULL;
        
        current->next = NULL; // assign the First current Node as NuLL before deleting Current
        delete current;
    }
    else
    {

        Node *current = head; // pointing towards Head Starting Node
        // Node *previous = current->prev; // Pointing to start of node Before Head

        int count = 1;

        while (count <= position - 1) // iteratively move from node to node
        {

            // previous = current;
            current = current->next;
            count++;
        }

        Node *previous = current->prev; // Pointing to start of node Before Head

        if (current->next == NULL) // If the Node to be deleted is the Last Node
        {
            previous->next = NULL; // Assign the Previous Node to be NULL before deleting the Last Node
            tail = current->prev;
            current->prev=NULL;
        }
        else // deleting at mid Node
        {
            previous->next = current->next;
            (current->next)->prev=previous;
            current->prev=NULL;
            current->next = NULL;
        }
        delete current;
    }
}

int main()
{
    Node *node1 = new Node(10);
    Node *head = node1;
    Node *tail = node1; // Tail pointed to Node 1 since it is the only node

    printNodes(head);
    getLength(head);
    insertAtHead(5, head);
    printNodes(head);
    insertAtHead(3, head);
    cout << endl
         << "Head is: " << head->data << endl;
    cout << "Tail is: " << tail->data << endl;
    printNodes(head);
    insertAtTail(20, head, tail);
    printNodes(head);

    insertAtPosition(3, 50, head, tail);
    printNodes(head);

    cout << endl
         << "Head is: " << head->data << endl;
    cout << "Tail is: " << tail->data << endl;

    deleteNodeByPosition(3, head,tail);
    printNodes(head);

    cout << endl
         << "Head is: " << head->data << endl;
    cout << "Tail is: " << tail->data << endl;

    deleteNodeByPosition(4, head,tail);
    printNodes(head);

    cout << endl
         << "Head is: " << head->data << endl;
    cout << "Tail is: " << tail->data << endl;
    return 0;
}