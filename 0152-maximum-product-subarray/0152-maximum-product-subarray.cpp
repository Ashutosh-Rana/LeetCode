class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size(),maxm=INT_MIN,pre=1,suf=1;
        for(int i=0;i<n;i++){
            pre=pre*nums[i];
            maxm=max(maxm,pre);
            if(!pre){
                pre=1;
            }
            suf=suf*nums[n-i-1];
            maxm=max(maxm,suf);
            if(!suf){
                suf=1;
            }
            // cout<<pre<<" "<<suf<<" "<<maxm<<endl;
        }
        return maxm;
    }
};