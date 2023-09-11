class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int,vector<int>> mp;
        unordered_map<int,int> mp2;
        int n=groupSizes.size();
        for(int i=0;i<n;i++){
            mp[groupSizes[i]].push_back(i);
            mp2[groupSizes[i]]++;
        }
        vector<vector<int>> res;
        for(auto it=mp.begin();it!=mp.end();it++){
            vector<int> tmp;
            int key=it->first;
            vector<int> val=it->second;
            for(int i=0;i<val.size();i++){
                tmp.push_back(val[i]);
                if(tmp.size()==key){
                    res.push_back(tmp);
                    tmp={};
                }
            }
        }
        return res;
    }
};