class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=0,n=nums.size(),sum=0,res=INT_MAX;
        while(l<n && r<=n){
            if(sum>=target){
                res=min(res,r-l);
                sum-=nums[l];
                l++;
            }
            else{
                if(r<n){
                    sum+=nums[r];
                }
                r++;
            }
        }
        // if(sum>=target){
        //     res=min(res,r-l);
        // }
        
        return res!=INT_MAX? res:0;
    }
};