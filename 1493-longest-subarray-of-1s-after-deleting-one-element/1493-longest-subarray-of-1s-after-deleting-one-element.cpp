class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int prev=0,cur=0,n=nums.size(),res=0,flag=1;
        for(int i=0;i<n;i++){
            if(!nums[i]){
                flag=0;
                prev=cur;
                cur=0;
            }
            else{
                cur++;
            }
            res=max(res,cur+prev);
        }
        return flag==0? res : n-1 ;
    }
};