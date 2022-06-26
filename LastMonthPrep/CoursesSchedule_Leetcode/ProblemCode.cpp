#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> Topo;
    vector<int> InDegree;
    vector<vector<int>> Graph;
    void kahn(int n)
    {
        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (InDegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            Topo.push_back(node);
            for (int neighbor : Graph[node])
            {
                InDegree[neighbor]--;
                if (InDegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }
    }
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
    {
        if (numCourses == 1)
        {
            Topo.push_back(0);
            return Topo;
        }
        Graph.resize(numCourses);
        InDegree.resize(numCourses);

        for (int i = 0; i < prerequisites.size(); i++)
        {
            Graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
            InDegree[prerequisites[i][0]]++;
        }
        kahn(numCourses);
        if (numCourses != Topo.size()) // To Check if Graph is DAG
        {
            Topo.clear();
            // Topo.push_back(0);
            return Topo;
        }
        return Topo;
    }
};

int main()
{

    return 0;
}
