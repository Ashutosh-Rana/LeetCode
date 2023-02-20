class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1,mid;
        while(l<=r){
            mid=(l+r)/2;
            if(target==nums[mid]){
                return mid;
            }
            else if(target>nums[mid]){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return r+1;
    }
};