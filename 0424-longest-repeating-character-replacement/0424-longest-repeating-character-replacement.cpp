class Solution {
private:
    int maxMap(unordered_map<char,int> mp){
        int maxm=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            maxm=max(maxm,it->second);
        }
        return maxm;
    }
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int l=0,res=0;
        for(int r=0;r<s.length();r++){
            // int wind_sz=r-l+1;
            mp[s[r]]++;
            while((r-l+1) - maxMap(mp)>k){
                mp[s[l]]--;
                l++;
            }
            res=max(res,r-l+1);
        }
        return res;
    }
};