class Solution {
private:
    bool checkPalindrome(string str){
        int l=0,r=str.size()-1;
        while(l<r){
            if(str[l]!=str[r]){
                return false;
            }
            l++,r--;
        }
        return true;
    }
    void dfs(int st,string s,vector<string> v,vector<vector<string>>& res){
        if(st>=s.size()){
            res.push_back(v);
            return;
        }
        for(int j=st;j<s.size();j++){
            string temp=s.substr(st,j-st+1);
            if(checkPalindrome(temp)){
                v.push_back(temp);
                dfs(st+temp.size(),s,v,res);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> v;
        dfs(0,s,v,res);
        return res;
    }
};