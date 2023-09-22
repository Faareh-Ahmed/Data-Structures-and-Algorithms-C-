/*
    check whether a LOOP exists in the Linked List
    using simple technique and also with Floyd Algorithm

    Remove the Loop in the Linked List
*/

#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data; // store integar data of the node
        this->next = NULL; // pointer to next node in the list
    }
};

// This function inserts a new node with the given data
// at the beginning of the list
void insertAtHead(int data, Node *&head)
{
    Node *temp = new Node(data); // creating new node set its data
    temp->next = head;           // set its next Point towards the Current Head
    head = temp;                 // updates the head pointer to point to the new node, making it the new head.
}
// This function inserts a new node with the given data
// at the end of the list
void insertAtTail(int data, Node *&tail)
{
    Node *temp = new Node(data); // creating new nodeset its data
    tail->next = temp;           // Make the Next of current of current Tail point to nnew node
    tail = temp;                 // updates tail pointer point to new node making it new tail
}

void insertAtPosition(Node *&head, Node *&tail, int position, int data)
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
        insertAtTail(data, tail);
        return;
    }

    Node *newnode = new Node(data); // Creating new Node to place the data
    Node *afternode = temp->next;
    temp->next = newnode; // Previous Node pointing to the New node
    newnode->next = afternode;
}

void deleteNodeByPosition(int position, Node *&head, Node *&tail)
{
    cout << "\nDeleting at Position: " << position << endl;

    if (position == 1) // We want to delete the First Node
    {
        Node *current = head; // temp Node that points to head
        head = head->next;    // make the Next Node as Head
        current->next = NULL; // assign the First current Node as NuLL before deleting Current
    }
    else
    {

        Node *current = head;  // pointing towards Head Starting Node
        Node *previous = NULL; // Pointing to start of node Before Head

        int count = 1;

        while (count <= position - 1) // iteratively move from node to node
        {

            previous = current;
            current = current->next;
            count++;
        }
        if (current->next == NULL) // If the Node to be deleted is the Last Node
        {
            previous->next = NULL; // Assign the Previous Node to be NULL before deleting the Last Node
            tail = previous;
        }
        else // deleting at mid Node
        {
            previous->next = current->next;
            current->next = NULL;
        }
        delete current;
    }
}

void printNodes(Node *&head)
{
    Node *temp = head;
    cout << "\nData: " << endl;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int getLength(Node *&head)
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
    return length;
}

void deleteNodeByData(int data, Node *&head, Node *&tail)
{
    Node *current = head;
    Node *previous = NULL;
    int count = 0;
    cout << endl
         << "Deleting All Nodes Having " << data << " as Data" << endl;
    while (current != NULL)
    {
        bool done = false;
        if (current->data == data)
        {
            if (current->next == NULL) // deleting last Node
            {
                Node *temp = current;
                previous->next = NULL;
                tail = previous;
                delete temp;
                done = true;
            }
            if (current == head) // deleting First Node
            {
                Node *temp = current;
                head = current->next;
                temp->next = NULL;
                delete temp;
                current = head;
                done = true;
            }
            else
            {
                Node *temp = current;
                previous->next = temp->next;
                current = temp->next;
                temp->next = NULL;
                delete temp;
                done = true;
            }
        }
        if (!done)
        {
            previous = current;
            current = current->next;
            count++;
        }
    }
}

Node *reverseLinkedList(Node *&head,Node *&tail)
{
    cout<<"reversed Linked List is:"<<endl;
    Node *current = head;
    Node *previous = NULL;
    Node *forward;
    tail=current;
    while (current != NULL)
    {
        forward = current->next;
        current->next = previous;
        previous = current;
        current = forward;
    }

    return previous;
}

bool checkLoopLinkedList(Node* &head)
{
    if(head==NULL)
    {
        return false;
    }
    Node *current=head;
    map <Node*,bool> visited;
    while(current!=NULL)
    {
        if(visited[current]==true)
        {
            return true;
        }
        visited[current]=true;
        current=current->next;
    }
    return false;

}

bool floydLoopDetection(Node* &head)
{
    Node* fast=head;
    Node* slow=head;
    while(slow!=NULL && fast!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
        if(fast==slow) //this is the starting point of the loop
        {
            return true;
        }
        // If want to remove the Loop from the Linked List 
        // make the node previous than starting point of loop
        // point to the NULL
    }
    return false;
}

int main()
{
    Node *node1 = new Node(10);
    cout << "Data Initially: " << node1->data << " Next Initially: " << node1->next << endl;

    Node *head = node1; // head pointed to Node 1
    Node *tail = node1; // Tail pointed to Node 1 since it is the only node
    printNodes(head);

    // insertAtHead(12,head); //making a new head with data field 12
    insertAtTail(12, tail);
    insertAtTail(13, tail);
    insertAtTail(15, tail);

    printNodes(head);
    insertAtPosition(head, tail, 1, 11);
    insertAtPosition(head, tail, 1, 8);
    insertAtPosition(head, tail, 1, 6);

    printNodes(head);
    // deleteNodeByPosition(3, head,tail);
    // printNodes(head);
    //     cout<<endl<<"Head is: "<<head->data<<endl;
    // cout<<"Tail is: "<<tail->data<<endl;
    // deleteNodeByPosition(1, head,tail);
    // printNodes(head);
    //     cout<<endl<<"Head is: "<<head->data<<endl;
    // cout<<"Tail is: "<<tail->data<<endl;
    // deleteNodeByPosition(3, head,tail);
    // printNodes(head);

    cout << endl
         << "Head is: " << head->data << endl;
    cout << "Tail is: " << tail->data << endl;
    getLength(head);

    // deleteNodeByData(13, head, tail);
    printNodes(head);
    getLength(head);

    cout << endl
         << "Head is: " << head->data << endl;
    cout << "Tail is: " << tail->data << endl;

    head = reverseLinkedList(head,tail);
    // tail->next=head;
    cout<<checkLoopLinkedList(head);
    printNodes(head);
    getLength(head);

    cout << endl
         << "Head is: " << head->data << endl;
    cout << "Tail is: " << tail->data << endl;

    return 0;
}