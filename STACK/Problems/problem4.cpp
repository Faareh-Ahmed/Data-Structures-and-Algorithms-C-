// Reverse the Stack using Recursion

#include <iostream>
#include <stack>
using namespace std;

void solve(stack<int> &st, int count, int size)
{
    if (count == size / 2) //base case
    {
        st.pop();
        return;
    }

    int num = st.top();
    st.pop();

    // recursive call
    solve(st, count + 1, size);

    st.push(num);
}

void deleteMiddleElement(stack<int> &st, int size)
{
    int count = 0;
    solve(st, count, size);
}

void addAtBottom(stack<int> &st, int data)
{
    if (st.empty()) //base case
    {
        st.push(data);
        return;
    }

    int num = st.top();
    st.pop();

    //recursive call
    addAtBottom(st, data);
    st.push(num);
}

void reverseStack(stack<int> &st)
{
    if(st.empty()) //base case
    {
        return;
    }

    int num=st.top();
    st.pop();

// recursive call
    reverseStack(st);

//add the element in the bottom of the stack to make it reverese
    addAtBottom(st,num);
}

int main()
{

    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    reverseStack(st);

    cout << "the Stack after Reversing\n";
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}