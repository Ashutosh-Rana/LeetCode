class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // bacabcd
        int n=s.size(),l=0,r=0,res=0;
        unordered_map<char,int> mp;
        for(int i=0;i<n;i++){
            if(!mp[s[i]]){
                mp[s[i]]++;
                // r++;
            }
            else{
                while(s[l]!=s[i]){
                    mp[s[l]]--;
                    l++;
                }
                l++;
            }
            // r++;
            res=max(res,i-l+1);
        }
        return res;
    }
};