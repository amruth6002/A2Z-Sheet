class Solution
{
public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>> &adj, int src)
    {
        vector<int> v(adj.size(), -1);
        vector<int> vis(adj.size(), 0);
        queue<pair<int, int>> q;
        q.push({src, 0});
        vis[src] = 1;
        v[src] = 0;
        while (!q.empty())
        {
            pair<int, int> k = q.front();
            q.pop();
            for (auto c : adj[k.first])
            {
                if (!vis[c])
                {
                    v[c] = k.second + 1;
                    q.push({c, k.second + 1});
                    vis[c] = 1;
                }
            }
        }
        return v;
    }
};