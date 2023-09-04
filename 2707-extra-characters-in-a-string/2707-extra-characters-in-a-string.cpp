class Solution {
    int recur(unordered_map<string,int> &mp,int idx,string &s,vector<int> &dp){
        if(idx>=s.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        string curStr="";
        int res=s.size(),cur,nextExtra,total;
        for(int i=idx;i<s.size();i++){
            curStr+=s[i];
            if(mp[curStr]) cur=0;
            else cur=curStr.size();
            nextExtra=recur(mp,i+1,s,dp);
            total=cur+nextExtra;
            res=min(res,total);
        }
        dp[idx]=res;
        return dp[idx];
    }
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n=s.size();
        vector<int> dp(n,-1);
        unordered_map<string,int> mp;
        for(string str:dictionary){
            mp[str]=1;
        }
        int res=recur(mp,0,s,dp);
        return res;
    }
};