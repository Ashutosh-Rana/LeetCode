class NumArray {
private:
    vector<int> dp;
public:
    NumArray(vector<int>& nums) {
        dp=nums;
        for(int i=1;i<dp.size();i++){
            dp[i]=dp[i-1]+dp[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0){
            return dp[right];
        }
        return dp[right]-dp[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */