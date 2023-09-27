#include <iostream>
#include <string>
#include <stack>
using namespace std;



int main()
{
    string word;
    cout<<"enter the String to reverese\n";
    getline(cin,word);

    stack<char> st;
    for(int i=0;i<word.length();i++)
    {
        char ch=word[i];
        st.push(ch);
    }

    string ans="";
    while(!st.empty())
    {
        char ch=st.top();
        ans.push_back(ch);
        st.pop();
    }

    cout<<"the reverse string is: "<<ans;

    return 0;
}