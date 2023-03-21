class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long res=0,cnt=0,n=nums.size();
        if(nums[0]==0){
            cnt=1;
        }
        for(int i=1;i<n;i++){
            if(nums[i]==0){
                cnt++;
            }
            else if(nums[i]!=0 && nums[i-1]==0){
                long long temp=(cnt*(cnt+1))/2;
                res+=temp;
                cnt=0;
            }
        }
        long long temp=(cnt*(cnt+1))/2;
        res+=temp;
        return res;
    }
};