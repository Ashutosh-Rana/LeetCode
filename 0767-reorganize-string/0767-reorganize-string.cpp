class Solution {
public:
    
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        for(char c:s){
            mp[c]++;
        }
        
        string res;
        priority_queue<pair<int,char>> pq;
        for(auto it:mp){
            pq.push(make_pair(it.second,it.first));
        }
        while(pq.size()>1){
            auto top1=pq.top();
            pq.pop();
            auto top2=pq.top();
            pq.pop();
            res.push_back(top1.second);
            top1.first--;
            res.push_back(top2.second);
            top2.first--;
            if(top1.first>0){
                pq.push(top1);
            }
            if(top2.first>0){
                pq.push(top2);
            }
        }
        if(!pq.empty()){
            auto top=pq.top();
            if(top.first>1){
                return "";
            }
            res+=top.second;
        }
        return res;
    }
};