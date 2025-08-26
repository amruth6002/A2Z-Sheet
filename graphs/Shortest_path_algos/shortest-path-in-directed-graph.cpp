// User function Template for C++
class Solution
{
public:
    void dfs(int i, stack<int> &st, vector<int> &vis, vector<vector<pair<int, int>>> adj)
    {
        vis[i] = 1;
        for (auto c : adj[i])
        {
            if (!vis[c.first])
            {
                dfs(c.first, st, vis, adj);
            }
        }
        st.push(i);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges)
    {
        vector<int> vis(V, 0);
        vector<vector<pair<int, int>>> adj(V);
        int inf = 1e9;
        for (auto edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            int d = edge[2];
            adj[u].push_back({v, d});
        }
        stack<int> st;
        vector<int> dis(V, inf);
        dis[0] = 0;
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, st, vis, adj);
            }
        }
        while (!st.empty())
        {
            int k = st.top();
            st.pop();
            for (auto c : adj[k])
            {
                dis[c.first] = min(dis[k] + c.second, dis[c.first]);
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (dis[i] == inf)
                dis[i] = -1;
        }
        return dis;
    }
};
