class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        //int inf=numeric_limits<int> :: min();
        unordered_map<int,int> mp;
        for(int a:nums){
            mp[a]++;
        }
        // multimap<int,int,greater<int>> mm;
        // for(auto it:mp){
        //     mm.insert({it.second,it.first});
        // }
        // int cnt=0;
        // for(auto it2:mm){
        //     res.push_back(it2.second);
        //     cnt++;
        //     if(cnt==k){
        //         break;
        //     }
        // }
        
        unordered_map<int,vector<int>> freq;
        // for(int i=1;i<=nums.size();i++){
        //     freq[i]=[];
        // }
        for(auto it:mp){
            freq[it.second].push_back(it.first);
        }
        for(int i=nums.size();i>=1;i--){
            for(int j=0;j<freq[i].size();j++){
                res.push_back(freq[i][j]);
                if(res.size()==k){
                    break;
                }
            }
            if(res.size()==k){
                break;
            }
        }
        
        return res;
    }
};