class Solution {
    vector<vector<int>> res;
    void backtrack(vector<int> &nums,vector<int> &tmp,vector<int> &vis){
        if(tmp.size()==nums.size()){
            res.push_back(tmp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                tmp.push_back(nums[i]);
                vis[i]=1;
                backtrack(nums,tmp,vis);
                tmp.pop_back();
                vis[i]=0;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int> vis(n,0),tmp;
        backtrack(nums,tmp,vis);
        return res;
    }
};