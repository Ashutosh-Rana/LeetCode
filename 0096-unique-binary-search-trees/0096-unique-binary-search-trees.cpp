class Solution {
public:
    int numTrees(int n) {
        // if(n==1){
        //     return 1;
        // }
        // if(n==2) return 2;
        // if(n==3) return 5;
        vector<int> dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<i;j++){
                dp[i]+=dp[j]*dp[i-j-1];
            }
        }
        return dp[n];
    }
};