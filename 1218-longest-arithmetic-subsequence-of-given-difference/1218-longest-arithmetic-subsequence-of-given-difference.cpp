class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();
        // vector<int> dp(n,1);
        // // dp[0]=1;
        // for(int i=0;i<n;i++){
        //     for(int j=i-1;j>=0;j--){
        //         if(arr[i]-arr[j]==difference){
        //             dp[i]=max(dp[j]+1,dp[i]);
        //             break;
        //             // cout<<i<<" "<<j<<" "<<dp[i]<<endl;
        //         }
        //     }
        // }
        // return *max_element(dp.begin(),dp.end());
        
        unordered_map<int,int> length;
        int res=1;
        for(int a:arr){
            length[a]=1+length[a-difference];
            res=max(res,length[a]);
        }
        return res;
    }
};