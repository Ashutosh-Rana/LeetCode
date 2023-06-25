class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        for(int i=0;i<nums.size();i++){
            if(s[i]=='R'){
                nums[i]+=d;
            }
            else{
                nums[i]-=d;
            }
        }
        int mod=1e9+7;
        // for(int i=0;i<nums.size();i++){
        //     for(int j=i+1;j<nums.size();j++){
        //         long a=nums[i],b=nums[j];
        //         res=(res+abs(a-b))%mod;
        //         // res%=mod;
        //     }
        // }
        sort(nums.begin(),nums.end());
        long long prefsum=0,res=0;
        for(int i=0;i<nums.size();i++){
            res+=(i*(long long)nums[i])-prefsum;
            res%=mod;
            prefsum+=(long long)nums[i];
        }
        return res;
    }
};