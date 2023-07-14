class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size(),n2=text2.size();
        vector<vector<int>> dp(n2+1,vector<int> (n1+1,0));
        for(int i=1;i<=n2;i++){
            for(int j=1;j<=n1;j++){
                if(text2[i-1]==text1[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n2][n1];
    }
};