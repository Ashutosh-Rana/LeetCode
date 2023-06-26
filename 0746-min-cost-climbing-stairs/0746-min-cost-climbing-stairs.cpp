class Solution {
    void solve(vector<int>& cost,vector<int>& dp){
        dp[0]=cost[0],dp[1]=cost[1];
        for(int i=2;i<cost.size();i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
    }
    int solve2(vector<int>& cost){
        int prev2=cost[0],prev1=cost[1];
        for(int i=2;i<cost.size();i++){
            int cur=cost[i]+min(prev1,prev2);
            prev2=prev1;
            prev1=cur;
        }
        return min(prev2,prev1);
    }
public:
    int minCostClimbingStairs(vector<int>& cost) {
        // int n=cost.size();
        // vector<int> dp(n);
        return solve2(cost);
        // return min(dp[n-1],dp[n-2]);
    }
};