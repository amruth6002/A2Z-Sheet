class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        int cnt2=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                  q.push({i,j});
                  vis[i][j]=1;
                  cnt2++;
                }
            }
        }
        int t=1;
         vector<vector<int>> ans(m,vector<int>(n,0));
        while(!q.empty())
        {
           pair<int,int> k=q.front();
           q.pop();
           cnt2--;
           if(k.second+1<n)
           {
             if(!vis[k.first][k.second+1]&&mat[k.first][k.second+1]==1)
             {
                q.push({k.first,k.second+1});
                ans[k.first][k.second+1]=t;
                vis[k.first][k.second+1]=1;
             }
           }
           if(k.second-1>=0)
           {
                  if(!vis[k.first][k.second-1]&&mat[k.first][k.second-1]==1)
             {
                q.push({k.first,k.second-1});
                ans[k.first][k.second-1]=t;
                vis[k.first][k.second-1]=1;
             }
           }
           if(k.first+1<m)
           {
                  if(!vis[k.first+1][k.second]&&mat[k.first+1][k.second]==1)
             {
                q.push({k.first+1,k.second});
                ans[k.first+1][k.second]=t;
                vis[k.first+1][k.second]=1;
             }
           }
           if(k.first-1>=0)
           {
                  if(!vis[k.first-1][k.second]&&mat[k.first-1][k.second]==1)
             {
                q.push({k.first-1,k.second});
                ans[k.first-1][k.second]=t;
                vis[k.first-1][k.second]=1;
             }
           }
           if(cnt2==0)
           {
            cnt2=q.size();
             t++;
           }
        }
        return ans;
    }
};