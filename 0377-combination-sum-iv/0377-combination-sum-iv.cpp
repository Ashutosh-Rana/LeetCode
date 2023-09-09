class Solution {
    
    int recur(vector<int> &nums,int target,vector<int> &dp){
        if(target<0) return 0;
        if(target==0){
            return 1;
        }
        if(dp[target]!=-1){
            return dp[target];
        } 
        int res=0;
        // int prev=-1;
        for(int j=0;j<nums.size();j++){
            // if(nums[j]==prev) continue;
            // prev=nums[j];
            if(target-nums[j]<0) break;
            res+=recur(nums,target-nums[j],dp);
        }
        dp[target]=res;
        return res;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        int sum=0;
        sort(nums.begin(),nums.end());
        vector<int> dp(target+1,-1);
        return recur(nums,target,dp);
        // return res;
    }
};