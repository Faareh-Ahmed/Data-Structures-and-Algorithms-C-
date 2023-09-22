/*
    Merge 2 Sorted Linked Lists
*/

#include <iostream>
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

Node *reverseLinkedList(Node *&head, Node *&tail)
{
    cout << "reversed Linked List is:" << endl;
    Node *current = head;
    Node *previous = NULL;
    Node *forward;
    tail = current;
    while (current != NULL)
    {
        forward = current->next;
        current->next = previous;
        previous = current;
        current = forward;
    }

    return previous;
}

Node *merge(Node *&first, Node *&second)
{
    Node *current1 = first;
    Node *forward1 = first->next;
    Node *current2 = second;

    if(first->next==NULL)
    {
        first->next=current2;
        return first;
    }

    while (forward1 != NULL && current2 != NULL)
    {
        if (current1->data <= current2->data && forward1->data >= current2->data)
        {
            current1->next = current2;
            Node *forward2 = current2->next;
            current2->next = forward1;
            current1=current2;
            current2=forward2;
        }else{
            current1=forward1;
            forward1=forward1->next;
            if(forward1==NULL)
            {
                current1->next=current2;
                return first;
            }
        }
    }
    return first;
}

Node *merge2SortedLists(Node *&first, Node *&second)
{
    if (first == NULL)
    {
        return second;
    }
    else if (second == NULL)
    {
        return first;
    }

    if (first->data <= second->data) //checks which head element is smaller
    {
        cout<<"selected1\n";
        first = merge(first, second);
        return first;
    }
    else
    {
                cout<<"selected2\n";

        first= merge(second, first);
        return first;
    }
}

int main()
{
    Node *node1 = new Node(38);
    Node *node2 = new Node(380);
    cout << "Data Initially: " << node1->data << " Next Initially: " << node1->next << endl;

    Node *head1 = node1; // head pointed to Node 1
    Node *tail1 = node1; // Tail pointed to Node 1 since it is the only node
    printNodes(head1);
    Node *head2 = node2; // head pointed to Node 1
    Node *tail2 = node2; // Tail pointed to Node 1 since it is the only node
    printNodes(head2);

    // insertAtHead(12,head); //making a new head with data field 12
    // insertAtTail(12, tail1);
    // insertAtTail(13, tail1);
    // insertAtTail(15, tail1);

    printNodes(head1);
    insertAtPosition(head1, tail1, 1, 10);
    insertAtPosition(head1, tail1, 1, 8);
    insertAtPosition(head1, tail1, 1, 3);

    insertAtPosition(head2, tail2, 1, 35);
    insertAtPosition(head2, tail2, 1, 7);
    insertAtPosition(head2, tail2, 1, 5);

    printNodes(head2);
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
         << "Head is: " << head1->data << endl;
    cout << "Tail is: " << tail1->data << endl;
    getLength(head1);

    // deleteNodeByData(13, head, tail);
    printNodes(head1);
    getLength(head1);

    cout << endl
         << "Head is: " << head1->data << endl;
    cout << "Tail is: " << tail1->data << endl;

    // head1 = reverseLinkedList(head1, tail1);
    printNodes(head1);
        printNodes(head2);

    getLength(head1);

    cout << endl
         << "Head is: " << head1->data << endl;
    cout << "Tail is: " << tail1->data << endl;

cout<<"Merging Linked List \n";
    Node* merged=merge2SortedLists(head1,head2);
    printNodes(merged);

    return 0;
}