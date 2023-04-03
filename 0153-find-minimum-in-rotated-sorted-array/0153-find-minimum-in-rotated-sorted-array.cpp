class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,n=nums.size(),r=n-1;
        // if(n==1){
        //     return nums[0];
        // }
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[l]<=nums[r]){
                return nums[l];
            }
            else if(nums[l]<=nums[mid]){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return 0;
    }
};