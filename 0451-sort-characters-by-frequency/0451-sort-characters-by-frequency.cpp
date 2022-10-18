class Solution {
public:
    string frequencySort(string s) {
        string res;
        unordered_map<char,int> mp;
        for(auto c:s){
            mp[c]++;
        }
        //unordered_map<int,string> freq;
        vector<string> freq(s.size()+1,"");
        // for(auto it:mp){
        //     for(int i=0;i<it.second;i++){
        //         freq[it.second].push_back(it.first);
        //     }
        // }
        for(auto it:mp){
            freq[it.second].append(it.second,it.first);
        }
        for(int i=s.length();i>=1;i--){
            // for(int j=0;j<freq[i].length();j++){
            //     res.push_back(freq[i][j]);
            // }
            if(!freq[i].empty()){
                res.append(freq[i]);
            }
        }
        
        
        return res;
    }
};