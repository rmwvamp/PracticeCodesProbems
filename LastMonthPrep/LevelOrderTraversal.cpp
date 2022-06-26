
#include <bits/stdc++.h>
using namespace std;

//  * Definition for a binary tree node.
  struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {};
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> LevelOrderTree;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            vector<int> temp;
            TreeNode *n = q.front();
            q.pop();
            if (n)
            {
                temp.push_back(n->val);
                if (n->left)
                {
                    q.push(n->left);
                }
                if (n->right)
                {
                    q.push(n->right);
                }
            }
        }
    }
};