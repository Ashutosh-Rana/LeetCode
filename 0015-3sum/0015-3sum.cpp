class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        // map<vector<int>,int> mp;
        int l=0,r=nums.size()-1,n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            l=i+1;
            r=n-1;
            while(l<r){
                int sum=nums[i]+nums[l]+nums[r];
                if(sum<0){
                    l++;
                }
                else if(sum>0){
                    r--;
                }
                else{
                    if(sum==0){
                        res.push_back({nums[i],nums[l],nums[r]});
                        while(l<r && nums[l]==nums[l+1]){
                            l++;
                        }
                        l++;
                        while(l<r && nums[r]==nums[r-1]){
                            r--;
                        }
                        r--;
                    }
                }
            }
        }
        return res;
    }
};