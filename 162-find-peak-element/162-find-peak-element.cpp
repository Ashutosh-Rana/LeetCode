class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int minimum = numeric_limits<int> :: min();
        nums.insert(nums.begin(),minimum);
        nums.push_back(minimum);
        int l=0,r=n+1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]>nums[mid+1] && nums[mid]>nums[mid-1]){
                return mid-1;
            }
            if(nums[mid]<nums[mid+1]){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return 0;
    }
};