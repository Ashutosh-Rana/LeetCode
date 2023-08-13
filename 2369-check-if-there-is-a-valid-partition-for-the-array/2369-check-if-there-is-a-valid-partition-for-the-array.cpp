class Solution {
    bool recur(vector<int>& nums,int i,vector<int> &dp){
        if(i>=nums.size()){
            return true;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        if(i+1<nums.size() && nums[i]==nums[i+1]){
            if(recur(nums,i+2,dp)){
                return true;
            }
            if(i+2<nums.size() && nums[i+2]==nums[i]){
                if(recur(nums,i+3,dp)){
                    return true;
                }
            }
        }
        if(i+2<nums.size() && nums[i]==nums[i+1]-1 && nums[i]==nums[i+2]-2){
            if(recur(nums,i+3,dp)){
                return true;
            }
        }
        return dp[i]=0;
    }
public:
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return recur(nums,0,dp);
    }
};