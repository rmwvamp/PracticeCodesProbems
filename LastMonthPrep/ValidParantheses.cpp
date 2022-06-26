#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }
            else
            {
                if (!st.empty())
                {
                    char ch = st.top();

                    st.pop();
                    if (s[i] == '}' && ch == '{')
                    {
                        continue;
                        // continue;
                    }
                    else if (s[i] == ')' && ch == '(')
                    {
                        continue;
                    }
                    else if (s[i] == ']' && ch == '[')
                    {
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        if (st.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};