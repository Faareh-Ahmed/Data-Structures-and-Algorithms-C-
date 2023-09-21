/*
    Curcular Linked List
    No start and End Point
    We use only either Head or Tail for insertion reference
    circular linked List can be Doubly  or Single Linked List
    Last Node->next will point to the First Node
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

void insertNode(Node* &tail, int data, int element) //we want to insert the data after the element specified bcz there is no start and head for Position
{
    if(tail==NULL) //Initializing Linked List (first Node)
    {
        Node* newnode=new Node(data);
        tail=newnode;
        newnode->next=newnode;
    }
    else{
        cout << "Inserting " << data << " after " << element << endl;
        Node* current = tail;
        do
        {
            if (current->data == element)
            {
                Node* temp = new Node(data);
                temp->next = current->next;
                current->next = temp;
                if (current == tail)  // Update tail if we insert after the last element
                    tail = temp;
                break;
            }
            current = current->next;
        } while (current != tail);
        


    }
}

void printNode(Node* &tail)
{
    Node* temp=tail;
    cout << endl << "Printing Nodes: " << endl;
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail);
    cout << endl;
}

int main()
{
    Node* tail=NULL;
    insertNode(tail,5,3);
    cout<<"tail is "<<tail->data<<endl;
    printNode(tail);
    insertNode(tail,10,5);
    cout<<"tail is "<<tail->data<<endl;

    printNode(tail);
    insertNode(tail,7,10);
    cout<<"tail is "<<tail->data<<endl;
 
    printNode(tail);
    insertNode(tail,100,5);
    cout<<"tail is "<<tail->data<<endl;
 
    printNode(tail);
    insertNode(tail,50,7);
    cout<<"tail is "<<tail->data<<endl;
 
    printNode(tail);
    return 0;
}