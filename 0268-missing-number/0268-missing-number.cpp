class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int n=nums.size(),sum=0,totalSum=(n*(n+1))/2;
        // for(int i=0;i<n;i++){
        //     sum+=nums[i];
        // }
        // return totalSum-sum;
        
        int res=nums.size();
        for(int i=0;i<nums.size();i++){
            res=res^i^nums[i];
        }
        return res;
    }
};