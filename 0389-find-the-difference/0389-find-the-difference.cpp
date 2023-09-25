class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char,int> mp1,mp2;
        for(char c:s){
            mp1[c]++;
        }
        for(char c:t){
            mp2[c]++;
        }
        for(char c:t){
            if(mp1[c]!=mp2[c]){
                return c;
            }
        }
        return ' ';
    }
};