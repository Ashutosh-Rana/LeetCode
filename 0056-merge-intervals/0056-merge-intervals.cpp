class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            pq.push({intervals[i][0],intervals[i][1]});
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            int top1=pq.top().first;
            int top2=pq.top().second;
            pq.pop();
            if(!res.size()){
                res.push_back({top1,top2});
            }
            else{
                int sz=res.size();
                if(top1>res[sz-1][1]){
                    res.push_back({top1,top2});
                }
                else{
                    res[sz-1][1]=max(res[sz-1][1],top2);
                }
            }
        }
        return res;
    }
};