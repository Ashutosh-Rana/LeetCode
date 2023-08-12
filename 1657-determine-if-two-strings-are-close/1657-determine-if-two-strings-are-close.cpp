class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n1=word1.size(),n2=word2.size();
        if(n1!=n2) return false;
        unordered_map<char,int> mp1,mp2;
        for(char c:word1){
            mp1[c]++;
        }
        for(char c:word2){
            mp2[c]++;
        }
        // if(mp1.size()!=mp2.size()) return false;
        unordered_map<int,int> mp1_val,mp2_val;
        for(auto it=mp1.begin();it!=mp1.end();it++){
            if(!mp2[it->first]) return false;
            mp1_val[it->second]++;
        }
        for(auto it=mp2.begin();it!=mp2.end();it++){
            mp2_val[it->second]++;
        }
        if(mp1_val!=mp2_val) return false;
        return true;
    }
};