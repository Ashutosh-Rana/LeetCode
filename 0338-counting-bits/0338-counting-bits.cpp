class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        if(n==0){
            return {0};
        }
        dp[0]=0,dp[1]=1;
        for(int i=1;i<=n;i++){
            if(i%2==0){
                dp[i]=dp[i/2];
            }
            else{
                dp[i]=dp[i/2]+dp[i%2];
            }
        }
        return dp;
        
        // vector<int> res(n+1);
        // res[0]=0;
        // for(int i=1;i<=n;i++){
        //     int cnt=0;
        //     int j=i;
        //     // while(j){
        //     //     j=j&(j-1);
        //     //     cnt++;
        //     // }
        //     // while(j){
        //     //     cnt+=j&1;
        //     //     j=j>>1;
        //     // }
        //     while(j){
        //         cnt+=j%2;
        //         j/=2;
        //     }
        //     res[i]=cnt;
        // }
        // return res;
    }
};