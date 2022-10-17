class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        int inf=numeric_limits<int> :: min();
        unordered_map<int,int> mp;
        for(int a:nums){
            mp[a]++;
        }
        multimap<int,int,greater<int>> mm;
        for(auto it:mp){
            mm.insert({it.second,it.first});
        }
        int cnt=0;
        for(auto it2:mm){
            res.push_back(it2.second);
            cnt++;
            if(cnt==k){
                break;
            }
        }
        return res;
    }
};