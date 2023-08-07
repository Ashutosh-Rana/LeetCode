class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> pos;
        for(int i=0;i<n;i++){
            pos[nums[i]].push_back(i);
        }
        int res=INT_MAX;
        for(auto it:pos){
            int num=it.first;
            vector<int> v=it.second;
            v.push_back(v[0]+n);
            int seconds=0;
            for(int i=1;i<v.size();i++){
                seconds=max(seconds,(v[i]-v[i-1])/2);
            }
            res=min(res,seconds);
        }
        return res;
    }
};