class Solution {
    void backtrack(int i,string &s,vector<string> &res,string &digits,
                   unordered_map<char,string> &mp){
        if(s.size()==digits.size()){
            res.push_back(s);
            return;
        }
        // int a=digits[i];
        // cout<<i<<" "<<a<<" "<<mp[a].size()<<endl;
        for(int j=0;j<mp[digits[i]].size();j++){
            s+=mp[digits[i]][j];
            // cout<<i<<" "<<s<<endl;
            backtrack(i+1,s,res,digits,mp);
            s.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp;
        mp['2']="abc",mp['3']="def",mp['4']="ghi",mp['5']="jkl",mp['6']="mno";
        mp['7']="pqrs",mp['8']="tuv",mp['9']="wxyz";
        string s;
        // cout<<mp[2].size();
        vector<string> res;
        if(!digits.size()){
            return res;
        }
        backtrack(0,s,res,digits,mp);
        return res;
    }
};