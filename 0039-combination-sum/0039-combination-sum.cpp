class Solution {
    vector<vector<int>> res;
private:
    void backtrack(int start,vector<int>& v,vector<int>& candidates, int remain){
        if(remain<0){
            return;
        }
        else if(remain==0){
            res.push_back(v);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            v.push_back(candidates[i]);
            backtrack(i,v,candidates,remain-candidates[i]);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        backtrack(0,v,candidates,target);
        return res;
    }
};