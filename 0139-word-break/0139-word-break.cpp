class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size(),m=wordDict.size();
        vector<bool> dp(n+1);
        dp[n]=true;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                int cnt=wordDict[j].size();
                if(i+cnt<=n && s.substr(i,cnt)==wordDict[j]){
                    dp[i]=dp[i+cnt];
                }
                if(dp[i]){
                    break;
                }
            }
        }
        return dp[0];
    }
};