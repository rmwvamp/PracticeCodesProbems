#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;
int a[MAXN], prefix_or[MAXN];
int n;

struct Node
{
    int or_val;
    Node *left;
    Node *right;
};

Node *build(int l, int r)
{
    if (l == r)
    {
        Node *node = new Node;
        node->or_val = a[l];
        node->left = nullptr;
        node->right = nullptr;
        return node;
    }
    int mid = (l + r) / 2;
    Node *left_child = build(l, mid);
    Node *right_child = build(mid + 1, r);
    Node *node = new Node;
    node->or_val = left_child->or_val | right_child->or_val;
    node->left = left_child;
    node->right = right_child;
    return node;
}

int query(Node *node, int ql, int qr, int l, int r)
{
    if (qr < l || ql > r)
    {
        return 0;
    }
    if (ql <= l && qr >= r)
    {
        return node->or_val;
    }
    int mid = (l + r) / 2;
    int left_val = query(node->left, ql, qr, l, mid);
    int right_val = query(node->right, ql, qr, mid + 1, r);
    return left_val | right_val;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            prefix_or[i] = prefix_or[i - 1] | a[i];
        }
        Node *root = build(1, n);
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int l = i, r = n;
            while (l < r)
            {
                int mid = (l + r + 1) / 2;
                int subarray_or = query(root, i, mid, 1, n);
                long long remaining_or = prefix_or[i - 1] | (prefix_or[n] ^ prefix_or[mid]);
                if ((subarray_or | remaining_or) <= k)
                {
                    l = mid;
                }
                else
                {
                    r = mid - 1;
                }
            }
            long long temp = (long long)(l - i + 1);
            cout << temp << endl;
            ans += temp;
        }
        cout << ans << endl;
    }
    return 0;
}
