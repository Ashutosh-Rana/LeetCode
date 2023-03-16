class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0,res=0;
        // unordered_map<char,int> mp;
        // for(int r=0;r<s.length();r++){
        //     if(mp[s[r]]==0){
        //         mp[s[r]]=1;
        //     }
        //     else{
        //         // mp[s[l]]=0;
        //         // l++;
        //         while(l<r && mp[s[r]]!=0){
        //             mp[s[l]]=0;
        //             l++;
        //         }
        //         mp[s[r]]=1;
        //     }
        //     res=max(res,r+1-l);
        // }
        
        unordered_set<char> st;
        while(r<s.length()){
            if(st.find(s[r])==st.end()){
                st.insert(s[r]);
                res=max(res,r+1-l);
                r++;
            }
            else{
                st.erase(s[l]);
                l++;
            }
        }
        return res;
    }
};