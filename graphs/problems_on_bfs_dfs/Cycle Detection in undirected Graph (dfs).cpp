class Solution {
  public:
  bool dfs(vector<vector<int>> &adj, int p,int parent,vector<bool> &vis)
  {
      vis[p]=true;
      for(auto c: adj[p])
      {
          if(!vis[c])
          {
              if(dfs(adj,c,p,vis)) return true;
          }
          else if(c!=parent)
          {
              return true;
          }
      }
      return false;
  }
    bool isCycle(int V, vector<vector<int>>& edges) {
       vector<vector<int>> adj(V);
       vector<bool> vis(V,false);
       for(int i=0;i<edges.size();i++)
       {
           adj[edges[i][0]].push_back(edges[i][1]);
           adj[edges[i][1]].push_back(edges[i][0]);
       }
       for(int i=0;i<V;i++)
       {
           if(!vis[i])
           {
              if(dfs(adj,i,-1,vis))
              {
                  return true;
              }
           }
       }
       return false;
    }
};