class Solution {
private:
    void helper(int n,int open,int close,vector<string> &res,string temp){
        if(open==close && open==n){
            res.push_back(temp);
        }
        if(close<open && open<n){
            temp+='(';
            helper(n,open+1,close,res,temp);
            temp.pop_back();
            temp+=')';
            helper(n,open,close+1,res,temp);
        }
        else if(open<n){
            temp+='(';
            helper(n,open+1,close,res,temp);
        }
        else if(close<n){
            temp+=')';
            helper(n,open,close+1,res,temp);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string temp="";
        helper(n,0,0,res,temp);
        return res;
    }
};