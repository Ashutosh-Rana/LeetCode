class Solution {
    vector<vector<int>> res;
    map<vector<int>,int> mp;
    void solve(vector<int>& candidates,vector<int>& v,int i,int sum,int target){
        // cout<<i-1<<" "<<sum<<endl;
        if(sum==target){
//             vector<int> tmp=v;
//             sort(tmp.begin(),tmp.end());
//             if(!mp[tmp]){
                 //res.push_back(v);
//                 mp[tmp]=1;
//             }
            res.push_back(v);
            return;
        }
        if(i>=candidates.size() or sum>target){
            return;
        }
        int prev=-1;
        for(int j=i;j<candidates.size();j++){
            if(candidates[j]==prev){
                continue;
            }
            v.push_back(candidates[j]);
            solve(candidates,v,j+1,sum+candidates[j],target);
            v.pop_back();
            prev=candidates[j];
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> v;
        int sum=0;
        sort(candidates.begin(),candidates.end());
        solve(candidates,v,0,sum,target);
        return res;
        
    }
};