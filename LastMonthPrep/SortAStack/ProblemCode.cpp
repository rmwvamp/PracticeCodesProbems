#include <bits/stdc++.h>
using namespace std;

void rec(stack<int> &st)
{
    if (st.size() == 0)
        return;
    // recursive case
    stack<int> st2;
    int temp = st.top();
    st.pop();
    rec(st);
    if (st.top() <= temp)
        st.push(temp);
    else
    {
        while (st.top() > temp)
        {
            st2.push(st.top());
            st.pop();
        }
        st.push(temp);
        while (!st2.empty())
        {
            st.push(st2.top());
            st2.pop();
        }
    }
}

int main()
{
    stack<int> s1;
    s1.push(2);
    s1.push(3);
    s1.push(1);
    s1.push(4);
    stack<int> s2;
    cout<<s1.size()<<endl;
    rec(s1);
    cout<<s1.size()<<endl;
    while(!s1.empty())
    {
        int temp=s1.top();
        s1.pop();
        cout<<temp<<endl;
    }
    cout<<s1.size()<<endl;

    return 0;
}
