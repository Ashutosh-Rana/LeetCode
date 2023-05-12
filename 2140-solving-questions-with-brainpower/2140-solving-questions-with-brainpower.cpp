class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        // long long res=0;
        vector<long long> dp(200001,0);
        int n=questions.size();
        for(int i=n-1;i>=0;i--){
            dp[i]=max(questions[i][0]+dp[questions[i][1]+i+1],dp[i+1]);
        }
        return dp[0];
    }
};