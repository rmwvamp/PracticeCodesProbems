#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    vector<Node *> Visited;
    void dfs(Node *node, Node *copy)
    {
        Visited[node->val] = copy;
        for (Node *neighbor : node->neighbors)
        {
            if (Visited[neighbor->val] == NULL)
            {
                Node *neighborcopy = new Node(neighbor->val);
                copy->neighbors.push_back(neighborcopy);

                dfs(neighbor, neighborcopy);
            }
            else
            {
                copy->neighbors.push_back(Visited[neighbor->val]);
            }
        }
    }
    Node *cloneGraph(Node *node)
    {
        if (node == NULL)
            return NULL;
        Visited.resize(10000, NULL);
        Node *CopyNode = new Node(node->val);
        dfs(node, CopyNode);
        return CopyNode;
    }
};

int main()
{

    return 0;
}
