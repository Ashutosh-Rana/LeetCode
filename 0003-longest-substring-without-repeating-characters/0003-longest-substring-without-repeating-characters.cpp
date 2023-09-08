class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int res=0,l=0;
        for(int i=0;i<s.size();i++){
            if(mp[s[i]]){
                while(s[l]!=s[i]){
                    mp[s[l]]=0;
                    l++;
                }
                mp[s[l]]=0;
                l++;
            }
            mp[s[i]]=1;
            res=max(res,i-l+1);
        }
        return res;
    }
};