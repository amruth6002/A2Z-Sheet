class Solution
{
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        int V = numCourses;
        vector<int> indegree(V, 0);
        vector<vector<int>> adj(V);
        for (const auto &edge : prerequisites)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        for (int i = 0; i < V; i++)
        {
            for (auto c : adj[i])
            {
                indegree[c]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty())
        {
            int n = q.front();
            q.pop();
            ans.push_back(n);
            for (auto c : adj[n])
            {
                indegree[c]--;
                if (indegree[c] == 0)
                    q.push(c);
            }
        }
        if (ans.size() != V)
            return false;
        else
        {
            return true;
        }
    }
};