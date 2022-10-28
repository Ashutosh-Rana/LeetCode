class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n=books.size();
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        for(int p=1;p<=n;p++){
            for(int i=p,w=0,h=0;i>0 && w+books[i-1][0]<=shelfWidth;i--){
                w+=books[i-1][0];
                h=max(h,books[i-1][1]);
                dp[p]=min(dp[p],h+dp[i-1]);
            }
        }
        return dp[n];
    }
};