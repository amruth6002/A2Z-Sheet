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
        for(int i=2;i<n;i++)
        {
            for(int j=i-2;j>=0;j--)
            {
               dp[i]=max(dp[i],dp[j]+nums[i]);
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;

    }
};