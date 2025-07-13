// User function Template for C++

class Solution {
  public:
  void dfs(vector<vector<int>> &adj,int k,vector<int> &vis)
  {
      vis[k]=1;
      int V = adj.size();
        for (int j = 0; j < V; ++j) {
            if (adj[k][j] == 1 && !vis[j]) {
                dfs(adj, j, vis);
            }
        }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
      int ans=0;
      vector<int>vis(V,0);
      for(int i=0;i<V;i++)
      {
          if(!vis[i])
          {
              dfs(adj,i,vis);
              ans++;
          }
      }
      return ans;
        
    }
};