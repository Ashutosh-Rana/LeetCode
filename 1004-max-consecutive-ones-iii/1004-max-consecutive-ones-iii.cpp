class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0,n=nums.size(),tmp=0,res=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                tmp++;
            }
            while(tmp>k){
                if(nums[l]==0){
                    tmp--;
                }
                l++;
            }
            res=max(res,i-l+1);
        }
        return res;
    }
};