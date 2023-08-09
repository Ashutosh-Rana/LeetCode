class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),l=0,r=n-1,mid;
        int res=0;
        while(l<r){
            int sum=nums[l]+nums[r];
            if(sum==k){
                res++;
                l++,r--;
            }
            else if(sum>k){
                r--;
            }
            else{
                l++;
            }
        }
        return res;
    }
};