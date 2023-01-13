#include <bits/stdc++.h>
using namespace std;

void insert(stack<int>&st, int val)
{
    if(st.top()>val &&!st.empty())
    {
        int temp= st.top();st.pop();
        insert(st, val);
        insert(st, temp);
    }
    else
    {
        st.push(val);
    }
   
}

void rec(stack<int> &st) 
{
   
   
}

int main()
{
    stack<int> s1;
    s1.push(2);
    s1.push(3);
    s1.push(1);
    s1.push(4);
    stack<int> s2;
    cout << s1.size() << endl;
    rec(s1);
    cout << s1.size() << endl;
    while (!s1.empty())
    {
        int temp = s1.top();
        s1.pop();
        cout << temp << endl;
    }
    cout << s1.size() << endl;

    return 0;
}
