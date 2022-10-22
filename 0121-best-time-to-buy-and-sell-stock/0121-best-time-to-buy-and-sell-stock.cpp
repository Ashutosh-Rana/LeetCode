class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> dp(n);
        int least=prices[0];
        dp[0]=0;
        for(int i=1;i<n;i++){
            least=min(least,prices[i]);
            dp[i]=max(dp[i-1],prices[i]-least);
        }
        return dp[n-1];
    }
};