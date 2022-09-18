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
        unsigned nums_sum=0,sum=0,n=nums.size();
        unordered_set<int> s(nums.begin(),nums.end());
        int n2=n-s.size();
        for(auto a:s){
            sum+=a;
        }
        for(int i=0;i<n;i++){
            nums_sum+=nums[i];
        }
        if(nums_sum>sum){
            return (nums_sum-sum)/n2;
        }
        return (sum-nums_sum)/n2;
        
    }
};