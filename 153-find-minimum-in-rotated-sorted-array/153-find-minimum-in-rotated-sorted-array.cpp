class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,r=nums.size()-1,mid,res=nums[0];
        while(l<=r){
            if(nums[l]<nums[r]){
                res=min(res,nums[l]);
                return res;
            }
            mid=l+(r-l)/2;
            res=min(res,nums[mid]);
            if(nums[mid]>=nums[l]){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return res;
    }
};