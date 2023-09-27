// Remove the Middle element from the Stack
// If stack was -------- 1 2 3 4 5
// Then new stack is---- 1 2 4 5

// Add the Element at the bottom if the Stack

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

int main()
{

    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    // deleteMiddleElement(st, st.size());
    addAtBottom(st, 1);

    cout << "the Stack after removing the middle element\n";
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}