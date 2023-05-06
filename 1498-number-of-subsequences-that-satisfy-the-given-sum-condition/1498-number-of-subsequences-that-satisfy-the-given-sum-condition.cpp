class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int res=0,mod=pow(10,9)+7;
        int n=nums.size(),r=n-1,l=0;
        vector<int> pows(n,1);
        for(int i=1;i<n;i++){
            pows[i]=2*pows[i-1]%mod;
        }
        while(l<=r){
            if(nums[l]+nums[r]>target){
                r--;
            }
            else{
                res=(res+pows[r-l])%mod;
                l++;
            }
        }
        return res;
    }
};