class Solution {
    vector<vector<int>> res;
private:
    void backtrack(int start,vector<int> &v,vector<int> &nums){
        if(start>nums.size()){
            return;
        }
        res.push_back(v);
        for(int i=start;i<nums.size();i++){
            v.push_back(nums[i]);
            if(find(res.begin(),res.end(),v)==res.end()){
                backtrack(i+1,v,nums);
            }
            v.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> v;
        sort(nums.begin(),nums.end());
        backtrack(0,v,nums);
        return res;
    }
};