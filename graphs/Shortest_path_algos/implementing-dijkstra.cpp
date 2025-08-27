// User Function Template
class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src)
    {
        vector<vector<pair<int, int>>> adj(V);
        for (auto c : edges)
        {
            int u = c[0];
            int v = c[1];
            int w = c[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        int inf = 1e9;
        vector<int> ans(V, inf);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
        q.push({0, src});
        ans[src] = 0;
        while (!q.empty())
        {
            pair<int, int> k = q.top();
            int node = k.second;
            int dis = k.first;
            q.pop();
            for (auto c : adj[node])
            {
                int adjnode = c.first;
                int edgw = c.second;
                if (dis + edgw < ans[adjnode])
                {
                    ans[adjnode] = dis + edgw;
                    q.push({ans[adjnode], adjnode});
                }
            }
        }
        return ans;
    }
};