class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1);
        dp[0]=0,dp[1]=nums[0];
        if(n>1){
            dp[2]=nums[1];
        }
        for(int i=3;i<=n;i++){
            dp[i]=max(dp[i-2],dp[i-3])+nums[i-1];
        }
        return max(dp[n],dp[n-1]);
    }
};