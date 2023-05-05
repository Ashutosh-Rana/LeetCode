class Solution {
    vector<vector<int>> res;
    
private:
    void recur(int k,int n,vector<int>& v,vector<int>& nums){
        res.push_back(v);
        for(int i=k;i<n;i++){
            v.push_back(nums[i]);
            recur(i+1,n,v,nums);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<int> v={};
        recur(0,n,v,nums);
        return res;
    }
};