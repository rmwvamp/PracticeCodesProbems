#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left, *right;
    node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

node *BuildTreeusingLevelOrderTraversal(vector<int> &arr, char *input)
{
    if (strlen(input) == 0 || arr.size() == 0)
        return NULL;
    node *root = new node(arr[0]);
    queue<node *> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < arr.size())
    {
        node *temp = q.front();
        q.pop();

        if (i >= arr.size())
        {
            break;
        }
        temp->left = new node(arr[i++]);
        q.push(temp->left);
        if (i >= arr.size())
        {
            break;
        }
        temp->right = new node(arr[i++]);
        q.push(temp->right);
    }
    return root;
}

int Sum(node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int leftsum = Sum(root->left);
    int rightsum = Sum(root->right);
    return root->data + leftsum + rightsum;
}
int CountTree(node *root, int RequiredSum)
{
    if (!root)
    {
        return 0;
    }
    int ans = 0;
    if (Sum(root) == RequiredSum)
    {
        ans = 1;
    }
    ans += CountTree(root->left, RequiredSum);
    ans += CountTree(root->right, RequiredSum);
    return ans;
}

void solve()
{
    char input[1001000];
    cin.ignore();
    cin.getline(input, 1001000);
    int RequiredSum;
    vector<int> arr;
    cin >> RequiredSum;

    char *Number = strtok(input, " ");
    while (Number)
    {
        arr.push_back(stoi(Number));
        Number = strtok(NULL, " ");
    }

    // Now my arr vector contains all the require numbers that I had

    // First Creating the Tree using Level Order Traversal on my arr vector
    node *root = BuildTreeusingLevelOrderTraversal(arr, input);

    int res = CountTree(root, RequiredSum);
    cout << res << endl;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
