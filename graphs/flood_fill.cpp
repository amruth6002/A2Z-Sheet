class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image[0].size();
        int m=image.size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        vis[sr][sc]=true;
        queue<pair<int,int>> q;
        q.push({sr,sc});
        while(!q.empty())
        {
            pair<int,int> k= q.front();
            int a=k.first,b=k.second;
            q.pop();
            if(b+1<n)
            {
              if(!vis[a][b+1]&&image[a][b+1]==image[a][b])
            {
                q.push({a,b+1});
                vis[a][b+1]=true;
            }
            }
            if(b-1>=0)
            {
                         if(!vis[a][b-1]&&image[a][b-1]==image[a][b])
            {
                q.push({a,b-1});
                vis[a][b-1]=true;
            }
            }
            if(a+1<m)
            {
  if(!vis[a+1][b]&&image[a+1][b]==image[a][b])
            {
                q.push({a+1,b});
                vis[a+1][b]=true;
            }
            }
            if(a-1>=0)
            {
  if(!vis[a-1][b]&&image[a-1][b]==image[a][b])
            {
                q.push({a-1,b});
                vis[a-1][b]=true;
            }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(vis[i][j]==true)
                {
                    image[i][j]=color;
                }
            }
        }
        
        return image;
    }
};