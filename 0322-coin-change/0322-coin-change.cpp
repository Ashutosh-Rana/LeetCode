class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount==0){
            return 0;
        }
        int Max=amount+1;
        vector<int> dp(amount+1,Max);
        dp[0]=0;
        for(int i=0;i<coins.size();i++){
            int st=coins[i];
            for(int j=st;j<=amount;j++){
                dp[j]=min(dp[j],dp[j-st]+1);
                // if(dp[j-st]==INT_MAX && dp[j]==INT_MAX){
                //     dp[j]=INT_MAX;
                // }
                // else if(dp[j-st]==INT_MAX){
                //     continue;
                // }
                // else if(dp[j]==INT_MAX){
                //     dp[j]=dp[j-st]+1;
                // }
                // else{
                //     dp[j]=min(dp[j],dp[j-st]+1);
                // }
            }
        }
        if(dp[amount]>amount){
            return -1;
        }
        return dp[amount];
    }
};