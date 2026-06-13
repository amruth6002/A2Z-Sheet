class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,0);
        int maxi=0;
        dp[0]=nums[0];
        if(n==1) return dp[0];
        dp[1]=nums[1];
        maxi=max(dp[0],dp[1]);
        for(int i=2;i<n-1;i++)
        {
            for(int j=i-2;j>=0;j--)
            {
                dp[i]=max(dp[i],dp[j]+nums[i]);
            }
            maxi=max(maxi,dp[i]);
        }
        vector<int> dp2(n,0);
        dp2[1]=nums[1];
        if(n==2) return maxi;
        dp2[2]=nums[2];
        int  maxi2=0;
        maxi2=max(dp2[1],dp2[2]);
        for(int i=3;i<n;i++)
        {
           for(int j=i-2;j>=1;j--)
           {
              dp2[i]=max(dp2[i],dp2[j]+nums[i]);
           }
           maxi2=max(maxi2,dp2[i]);
        }
      int ans=max(maxi,maxi2);
      return ans;
    }
};