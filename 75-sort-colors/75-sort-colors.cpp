class Solution {
public:
    void sortColors(vector<int>& nums) {
        int high=nums.size()-1,l=0,mid=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i+1;j<n;j++){
        //         if(nums[i]>nums[j]){
        //             swap(nums[i],nums[j]);
        //         }
        //     }
        // }
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[l],nums[mid]);
                l++,mid++;
            }
            else if(nums[mid]==1){
                mid++;
            }
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
    }
};