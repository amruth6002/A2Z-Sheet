class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> vis(200,vector<int>(200,0));
        queue<pair<int,int>> q;
        int cnt=0,cnt2=0;
        int n=grid[0].size();
        int m=grid.size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({i,j});
                    vis[i][j]=1;
                    cnt2++;
                }
                if(grid[i][j]==1){
                    cnt++;
                }
            }
        }
        int ans=0;
        while(!q.empty())
        {
            pair<int,int> k=q.front();
            q.pop();
            cnt2--;
            if(k.second+1<n)
            {
               if(!vis[k.first][k.second+1]&&grid[k.first][k.second+1]==1)
               {
                vis[k.first][k.second+1]=1;
               q.push({k.first,k.second+1});
               cnt--;
               }
               
            }
            if(k.second-1>=0)
            {
                if(!vis[k.first][k.second-1]&&grid[k.first][k.second-1]==1)
                {
                    vis[k.first][k.second-1]=1;
                cnt--;
                q.push({k.first,k.second-1});
                }
            }
            if(k.first+1<m)
            {
                if(!vis[k.first+1][k.second]&&grid[k.first+1][k.second]==1)
                {
                    vis[k.first+1][k.second]=1;
                 cnt--;
                q.push({k.first+1,k.second});
                }
            }
            if(k.first-1>=0)
            {
                if(!vis[k.first-1][k.second]&&grid[k.first-1][k.second]==1)
                {
                    vis[k.first-1][k.second]=1;
                cnt--;
                q.push({k.first-1,k.second});
                }
            }
            if(cnt2==0)
            {
                ans++;
                cnt2=q.size();
            }
        }
        if(cnt==0)
        {
            if(ans==0) return 0;
            return ans-1;
        }
        else
        {
            return -1;
        }
    }
};