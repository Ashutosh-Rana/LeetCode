class Solution {
private:
    void dfs(vector<string>& res,string s,string digits,unordered_map<char,string> mp,int p){
        if(p==digits.size()){
            res.push_back(s);
            return;
        }
        // cout<<p<<endl<<mp[digits[p]].size();
        for(int i=0;i<mp[digits[p]].size();i++){
            s+=mp[digits[p]][i];
            //cout<<s<<endl;
            dfs(res,s,digits,mp,p+1);
            s.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp;
        mp['2']="abc",mp['3']="def",mp['4']="ghi",mp['5']="jkl",mp['6']="mno",mp['7']="pqrs";
        mp['8']="tuv",mp['9']="wxyz";
        vector<string> res;
        if(digits.size()==0){
            return res;
        }
        string s;
        dfs(res,s,digits,mp,0);
        return res;
    }
};