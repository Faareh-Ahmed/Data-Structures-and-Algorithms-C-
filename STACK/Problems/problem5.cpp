// Sort the Stack

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

void insertSortedStack(stack<int> &st , int data)
{
    if(st.empty() || (!st.empty() && st.top()<data)) //base case
    {
        st.push(data);
        return;
    }

    int num=st.top();
    st.pop();

    // recursive call
    insertSortedStack(st,data);

    st.push(num);

}

void sortStack(stack<int> &st)
{
    if(st.empty()) //base case
    {
        return;
    }

    int num=st.top();
    st.pop();

    //resursive call

    sortStack(st);

    insertSortedStack(st,num);


}


int main()
{

    stack<int> st;
    st.push(100);
    st.push(70);
    st.push(30);
    st.push(40);
    st.push(20);
    st.push(60);

    sortStack(st);

    cout << "the Stack after Reversing\n";
    while (!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}