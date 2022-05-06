// Stack.cpp
#include <iostream>
#include <stack>
using namespace std;

bool CheckBalanced(char *a)
{

    stack<char> s;

    for (int i = 0; a[i] != '\0'; i++)
    {
        char ch = a[i];
        switch (ch)
        {
        case '{':
        case '(':
        case '[':
            s.push(ch);
            break;
        case '}':
            if (!s.empty() && s.top() == '{')
            {
                s.pop();
            }
            else
            {
                return false;
            }
            break;
        case ')':
            if (!s.empty() && s.top() == '(')
            {
                s.pop();
            }
            else
            {
                return false;
            }
            break;
        case ']':
            if (!s.empty() && s.top() == '[')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }

    // if(s.empty()){
    // 	return true;
    // }
    // else{
    // 	return false;
    // }
    return s.empty();
}

int main()
{
    char a[] = "{a+(b+c)+[d+(e+f)]}";

    if (CheckBalanced(a))
    {
        cout << "Balanced!" << endl;
    }
    else
    {
        cout << "Not Balanced!" << endl;
    }

    cout << endl;
    return 0;
}