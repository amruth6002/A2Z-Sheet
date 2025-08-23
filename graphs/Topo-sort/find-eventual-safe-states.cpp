class Solution
{
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph)
    {
        int V = graph.size();
        vector<int> outdegree(V, 0);
        vector<vector<int>> adj(V);
        for (int i = 0; i < V; i++)
        {
            for (auto c : graph[i])
            {
                adj[c].push_back(i);
                outdegree[i]++;
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            if (outdegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> ans;
        while (!q.empty())
        {
            int k = q.front();
            q.pop();
            ans.push_back(k);
            for (auto c : adj[k])
            {
                outdegree[c]--;
                if (outdegree[c] == 0)
                    q.push(c);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};