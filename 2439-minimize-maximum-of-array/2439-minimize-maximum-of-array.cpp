class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size();
        long long res=0;
        long long sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            long long temp=ceil((double)sum/(i+1));
            res=max(res,temp);
        }
        return res;
    }
};