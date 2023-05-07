class Solution {
    vector<vector<int>> res;
private:
    void backtrack(vector<int>& v,vector<int>& nums){
        if(v.size()==nums.size()){
            res.push_back(v);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(find(v.begin(),v.end(),nums[i])!=v.end()){
                continue;
            }
            v.push_back(nums[i]);
            backtrack(v,nums);
            v.pop_back();
        }
        
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> v;
        backtrack(v,nums);
        return res;
    }
};