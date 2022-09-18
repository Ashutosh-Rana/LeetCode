class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size()-1;i++){
        //     if(nums[i]==nums[i+1]){
        //         return nums[i];
        //     }
        // }
        // return 0;
        int slow=nums[0],fast=nums[0];
        do{
            slow=nums[slow];  //move 1 step ahead
            fast=nums[nums[fast]];  //move 2 step ahead
        }
        while(slow!=fast);
        
        fast=nums[0];
        while(slow!=fast){
            slow=nums[slow]; //move 1 step ahead
            fast=nums[fast];  //move 1 step ahead
        } 
        return slow;
    }
};