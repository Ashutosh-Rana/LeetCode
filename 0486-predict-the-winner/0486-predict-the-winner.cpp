class Solution {
    long long dp[20][20][2];
    long long helper(vector<int>& nums,int i,int j,int chance){
        if(i>j){
            return 0;
        }
        if(dp[i][j][chance]!=-1){
            return dp[i][j][chance];
        }
        if(chance==0){
            return dp[i][j][chance]=
                max(nums[i]+helper(nums,i+1,j,1),nums[j]+helper(nums,i,j-1,1));
        }
        else{
            return dp[i][j][chance]=
                min(helper(nums,i+1,j,0),helper(nums,i,j-1,0));
        }
    }
public:
    bool PredictTheWinner(vector<int>& nums) {
        long long total=0,p_two,n=nums.size();
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        long long p_one=helper(nums,0,n-1,0);
        p_two=total-p_one;
        return p_one>=p_two;
    }
};