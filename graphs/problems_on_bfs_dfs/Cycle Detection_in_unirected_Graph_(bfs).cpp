class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
       vector<vector<int>> adj(V);
       vector<bool> vis(V,false);
       for(int i=0;i<edges.size();i++)
       {
           adj[edges[i][0]].push_back(edges[i][1]);
           adj[edges[i][1]].push_back(edges[i][0]);
       }
       int p=-1;
       for(int i=0;i<V;i++)
       {
           if(vis[i]) continue;
           vis[i]=true;
         queue<pair<int,int>> q;
         q.push({i,-1});
         vis[0]=true;
         while(!q.empty())
         {
           pair<int,int> k=q.front();
           int a=k.first;
           int p=k.second;
           q.pop();
           for(auto c: adj[a])
           {
               if(vis[c]==true)
               {
                   if(c==p) continue;
                   return true;
               }
               else
               {
                   vis[c]=true;
                   q.push({c,a});
               }
           }
       }    
       }
       
       return false;
        
    }
};