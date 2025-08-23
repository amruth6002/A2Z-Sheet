class Solution
{
public:
    void dfs(int i, stack<int> &st, vector<int> &vis, const vector<vector<int>> &adj)
    {
        vis[i] = 1;
        for (auto c : adj[i])
        {
            if (!vis[c])
            {
                dfs(c, st, vis, adj);
            }
        }
        st.push(i);
    }
    vector<int> topoSort(int V, vector<vector<int>> &edges)
    {
        vector<int> vis(V, 0);
        stack<int> st;
        vector<vector<int>> adj(V);
        for (const auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfs(i, st, vis, adj);
            }
        }
        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};