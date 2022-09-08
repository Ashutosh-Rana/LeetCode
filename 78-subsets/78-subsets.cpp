class Solution {
public:
    void recurFunction(int i,vector<int> v,vector<vector<int>>& res,vector<int>& nums){
        if(i==nums.size()){
            return;
        }
        v.push_back(nums[i]);
        res.push_back(v);
        recurFunction(i+1,v,res,nums);
        v.pop_back();
        recurFunction(i+1,v,res,nums);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> v;
        res.push_back(v);
        recurFunction(0,v,res,nums);
        return res;
    }
};