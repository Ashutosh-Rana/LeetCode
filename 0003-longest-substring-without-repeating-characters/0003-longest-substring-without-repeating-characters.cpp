class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,res=0;
        unordered_map<char,int> mp;
        for(int r=0;r<s.length();r++){
            if(mp[s[r]]==0){
                mp[s[r]]=1;
            }
            else{
                // mp[s[l]]=0;
                // l++;
                while(l<r && mp[s[r]]!=0){
                    mp[s[l]]=0;
                    l++;
                }
                mp[s[r]]=1;
            }
            res=max(res,r+1-l);
        }
        return res;
    }
};