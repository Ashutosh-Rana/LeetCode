class Solution {
    bool backtrack(string s, vector<string>& wordDict,string &s2,vector<int> &dp){
        if(s2==s){
            dp[s2.size()]=1;
            return true;
        }
        int n=s.length(),n2=s2.length();
        string tmp;
        if(n2<=n){
            tmp=s.substr(0,n2);
        }
        else{ return false; }
        // cout<<tmp<<" "<<n2<<endl;
        if(tmp!=s2) return false;
        if(dp[n2]!=-1) return dp[n2];
        for(int i=0;i<wordDict.size();i++){
            s2+=wordDict[i];
            // cout<<s2<<endl;
            if(backtrack(s,wordDict,s2,dp)) return true;
            int pos=s2.size()-wordDict[i].size();
            s2.erase(pos,wordDict[i].size());
        }
        dp[n2]=0;
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        string s2;
        int n=s.size();
        vector<int> dp(n+1,-1);
        return backtrack(s,wordDict,s2,dp);
    }
};