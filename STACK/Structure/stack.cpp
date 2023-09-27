#include <iostream>
using namespace std;

class Stack{
public:
//attributes
int *arr;
int top;
int size;

//constructor
Stack(int size)
{
    this->size=size;
    top=-1;
    arr=new int[size];
}

//methods

void push(int element)
{
    if(top>=size-1) //If the Stack is already Full
    {
        cout<<"Stack Overflow\n";
    }else{
        arr[++top]=element;
    }
}

void pop()
{
    if(top>=0)
    {
        top--;
    }else{
        cout<<"Stack Underflow\n";
    }

}

bool isEmpty()
{
    return (top<size && top>=0);

}

int peek()
{
    if(top>=0 && top<size)
        return arr[top];
    else{
        cout<<"Cannot peek\n";
        return -1;
    }
    
    
}

};

int main()
{
    Stack st(3); //creating stack of size 5

    st.push(10);
    st.push(20);
    st.push(30);
    st.push(100);
    cout<<"Peek Element is: "<<st.peek()<<endl;
    st.pop();
    cout<<"Peek Element is: "<<st.peek()<<endl;
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);
    cout<<"Peek Element is: "<<st.peek()<<endl;
    st.pop();
    cout<<"Peek Element is: "<<st.peek()<<endl;

    return 0;
}