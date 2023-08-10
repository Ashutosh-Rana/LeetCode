class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        for(char c:s){
            mp[c]++;
        }
        int res=0,flag=0,tmp=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second%2==0){
                res+=it->second;
            }
            else{
                flag=1;
                res+=it->second-1;
            }
        }
        if(flag) res++;
        return res;
    }
};