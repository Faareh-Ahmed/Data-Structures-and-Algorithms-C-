// check if the Parenthesis is Valid
// [{()}]-------> valid
// [(}]--------> Not valid
#include <iostream>
#include <stack>
using namespace std;

bool isValidParenthesis(string expression)
{
    stack<char> st;
    for (int i = 0; i < expression.length(); i++)
    {
        char ch = expression[i]; //store each character of the expression

        if (ch == '(' || ch == '{' || ch == '[') //if starting bracket then push
        {
            st.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') //if closing bracket then Pop 
        {
            if (!st.empty())
            {
                char top = st.top();
                if ((top == '(' && ch == ')') || (top == '{' && ch == '}') || (top == '[' && ch == ']'))
                {
                    st.pop();
                }
            }else{
                return false;
            }
        }
    }
    if(!st.empty())
    {
        return false;
    }else{
        return true;
    }
}

int main()
{
    string expression;
    cout << "Enter the Parenthesis:\n";
    cin >> expression;

    cout << isValidParenthesis(expression) << endl;
    return 0;
}