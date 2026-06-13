class Solution {
  public:
    int minimizeCost(int k, vector<int>& arr) {
        int n=arr.size();
        const int inf=1000000;
        vector<int> dp(n,inf);
        dp[0]=0;
        dp[1]=abs(arr[0]-arr[1]);
        
        for(int i=2;i<n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                if(i-j>=0)
                {
                    dp[i]=min(dp[i],dp[i-j]+abs(arr[i]-arr[i-j]));
                }
            }
        }
        return dp[n-1];
            
        
        
    }
};