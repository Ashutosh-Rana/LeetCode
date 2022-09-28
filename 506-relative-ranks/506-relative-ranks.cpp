class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<int> pq;
        for(int a:score){
            pq.push(a);
        }
        int cnt=1;
        unordered_map<int,int> mp;
        for(int i=0;i<score.size();i++){
            mp[pq.top()]=cnt;
            pq.pop();
            cnt++;
        }
        vector<string> res;
        for(int a:score){
            if(mp[a]==1){
                res.push_back("Gold Medal");
            }
            else if(mp[a]==2){
                res.push_back("Silver Medal");
            }
            else if(mp[a]==3){
                res.push_back("Bronze Medal");
            }
            else{
                res.push_back(to_string(mp[a]));
            }
        }
        return res;
    }
};