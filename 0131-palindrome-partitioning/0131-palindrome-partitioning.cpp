class Solution {
    bool checkPal(string s){
        int n=s.size();
        for(int i=0;i<n/2;i++){
            if(s[i]==s[n-1-i]){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
    void solve(string s,int i,vector<vector<string>> &res,vector<string>& v){
        int n=s.size();
        if(i==n){
            res.push_back(v);
            return;
        }
        
        int cnt=0;
        for(int j=i;j<n;j++){
            cnt++;
            string tmp=s.substr(i,cnt);
            if(checkPal(tmp)){
                v.push_back(tmp);
                // cout<<i<<" "<<cnt<<" "<<tmp<<endl;
                solve(s,i+cnt,res,v);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> v;
        solve(s,0,res,v);
        return res;
    }
};