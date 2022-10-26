class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount+1,0);
        int n=coins.size();
        vector<int> nextDP(amount+1);
        //dp[0]=1;
        for(int i=n-1;i>=0;i--){
            nextDP[0]=1;
            for(int a=1;a<=amount;a++){
                nextDP[a]=dp[a];
                if(a-coins[i]>=0){
                    nextDP[a]+=nextDP[a-coins[i]];
                }
            }
            dp=nextDP;
        }
        return dp[amount];
    }
};