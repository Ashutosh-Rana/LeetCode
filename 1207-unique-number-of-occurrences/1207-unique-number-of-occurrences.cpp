class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp,check;
        for(int a:arr){
            mp[a]++;
        }
        for(auto it=mp.begin();it!=mp.end();it++){
            check[it->second]++;
            if(check[it->second]>1) return false;
        }
        return true;
    }
};