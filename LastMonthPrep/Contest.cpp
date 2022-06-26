#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double calculateTax(vector<vector<int>> &brackets, int income)
    {
        double ans = 0;
        int i = 0;
        while (income >= 0)
        {
            double amount = income - brackets[i][0];
            amount < 0 ? income : amount;
            income = amount;
            ans += (amount * brackets[i][1]) / 100.0;
            i++;
        }
        return ans;
    }
};

class Solution
{
public:
    double calculateTax(vector<vector<int>> &brackets, int income)
    {
        double ans = 0;
        int i = 0;
        while (income >= 0)
        {
            if (income - brackets[i][0] <= 0)
            {
                ans += (brackets[i++][1] * income) / 100.0;
                break;
            }
            else
            {
                income -= brackets[i][0];
                ans += (brackets[i][1] * brackets[i++][0]) / 100.0;
            }
        }
        return ans;
    }
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> preorder;
        if (!root)
            return preorder;
        TreeNode *curr = root;

        while (!curr)
        {
            if (!curr->left)
            {
                preorder.push_back(curr->val);
                curr = curr->right;
            }
            else
            {

                TreeNode *LeftMostRight = curr->left;
                while (LeftMostRight->right && LeftMostRight->right != curr)
                {
                    LeftMostRight = LeftMostRight->right;
                }
                if (!LeftMostRight->right)
                {
                    preorder.push_back(curr->val);
                    LeftMostRight->right = curr;
                    curr = curr->left;
                }
                else
                {
                    curr = curr->right;
                    LeftMostRight->right = NULL;
                }
            }
        }
        return preorder;
    }
};