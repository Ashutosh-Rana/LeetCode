class Solution {
public:
    string frequencySort(string s) {
        string res;
        unordered_map<char,int> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        unordered_map<int,string> freq;
        for(auto it:mp){
            for(int i=0;i<it.second;i++){
                freq[it.second].push_back(it.first);
            }
        }
        for(int i=s.length();i>=1;i--){
            for(int j=0;j<freq[i].length();j++){
                res.push_back(freq[i][j]);
            }
        }
        return res;
    }
};