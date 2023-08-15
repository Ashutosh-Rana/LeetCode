class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int pre=0,post=0;
        for(int a:nums) post+=a;
        post-=nums[0];
        if(pre==post) return 0;
        for(int i=1;i<n;i++){
            pre+=nums[i-1];
            post-=nums[i];
            if(pre==post) return i;
        }
        
        return -1;
    }
};