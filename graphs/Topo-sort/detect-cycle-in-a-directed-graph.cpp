class Solution
{
public:
    bool isCyclic(int V, vector<vector<int>> &edges)
    {
        vector<int> indegree(V, 0);
        vector<vector<int>> adj(V);
        for (const auto &edge : edges)
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
            return true;
        else
        {
            return false;
        }
    }
};