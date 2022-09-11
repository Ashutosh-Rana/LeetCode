class Solution {
private :
    void backtrack(int n,int open,int close,string& s,vector<string>& res){
    if(open==n && close==n){
        res.push_back(s);
        return;
    }
    if(open<n){
        s+="(";
        backtrack(n,open+1,close,s,res);
        s.pop_back();
    }
    if(close<open){
        s+=")";
        backtrack(n,open,close+1,s,res);
        s.pop_back();
    }
}
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        backtrack(n,0,0,s,res);
        return res;
    }
};