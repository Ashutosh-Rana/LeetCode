class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int cur=0,odd=0;
        for(int cur=0;cur<nums.size();cur++){
            if(nums[cur]%2==0){
                swap(nums[cur],nums[odd]);
                odd++;
            }
        }
        return nums;
    }
};