class Solution {
    int solve(vector<int> a){
        int prev2=0,prev1=a[0];
        for(int i=1;i<a.size();i++){
            int curr=max(prev1,a[i]+prev2);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
public:
    int rob(vector<int>& nums) {
        vector<int> tmp,tmp2;
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        for(int i=0;i<n;i++){
            if(i!=0){
                tmp.push_back(nums[i]);
            }
            if(i!=n-1){
                tmp2.push_back(nums[i]);
            }
        }
        return max(solve(tmp),solve(tmp2));
    }
};