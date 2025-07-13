class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> vis(n,-1);
        queue<int> q;
        bool ans=true;
        for(int i=0;i<n;i++)
        {
            if(vis[i]==-1)
            {
                q.push(i);
                vis[i]=0;
                while(!q.empty())
                {
                    int v=q.front();
                    q.pop();
                    for(auto u:graph[v])
                    {
                        if(vis[u]==-1)
                        {
                            vis[u]=vis[v]^1;
                            q.push(u);
                        }
                        else
                        {
                             ans&=vis[u]!=vis[v];
                        }
                    }
                }
            }
        }
        return ans;
    }
};