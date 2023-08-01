class Solution {
    vector<vector<int>> res;
    void dfs(int n,int k,int i,vector<int> &tmp){
        if(tmp.size()==k){
            res.push_back(tmp);
            return;
        }
        if(i>n) return;
        for(int j=i;j<=n;j++){
            tmp.push_back(j);
            dfs(n,k,j+1,tmp);
            tmp.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> tmp;
        dfs(n,k,1,tmp);
        return res;
    }
};