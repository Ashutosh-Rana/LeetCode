class Solution {
    // unordered_map<int,long> dp;
    // int mod=1e9+7;
// private:
//     long dfs(int length,int low, int high, int zero, int one){
//         if(length>high){
//             return 0;
//         }
//         if(dp[length]){
//             return dp[length];
//         }
//         if(length>=low){
//             dp[length]=1;
//         }
//         else{
//             dp[length]=0;
//         }
//         dp[length]+=dfs(length+zero,low,high,zero,one)
//             +dfs(length+one,low,high,zero,one);
//         return dp[length]%mod;
//     }    
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        // int res=dfs(0,low,high,zero,one);
        int mod=1e9+7;
        vector<int> dp(high+1,0);
        dp[0]=1;
        for(int i=min(zero,one);i<=high;i++){
            if(i>=zero){
                dp[i]=(dp[i] + dp[i-zero])%mod;
            }
            if(i>=one){
                dp[i]=(dp[i] + dp[i-one])%mod;
            }
        }
        int sum=0;
        for(int i=low;i<=high;i++){
            sum=(sum+dp[i])%mod;
        }
        return sum;
    }
};