class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        map<vector<int>,int> mp;
        int l=0,r=nums.size()-1;
        for(int i=0;i<nums.size();i++){
            l=i+1;
            r=nums.size()-1;
            while(l<r){
                if(nums[i]+nums[l]+nums[r]<0){
                    l++;
                }
                else if(nums[i]+nums[l]+nums[r]>0){
                    r--;
                }
                else{
                    if(mp[{nums[i],nums[l],nums[r]}]==0){
                        res.push_back({nums[i],nums[l],nums[r]});
                        mp[{nums[i],nums[l],nums[r]}]=1;
                        l++;
                        r--;
                    }
                    else{
                        l++;
                        r--;
                    }
                }
            }
        }
        return res;
    }
};