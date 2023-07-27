class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        // for(int i=0;i<n;i++){
        //     pq.push({intervals[i][0],intervals[i][1]});
        // }
        int start=intervals[0][0],end=intervals[0][1],res=0;
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=end){
                start=intervals[i][0],end=intervals[i][1];
            }
            else{
                res++;
                if(end>intervals[i][1]){
                    start=intervals[i][0],end=intervals[i][1];
                }
            }
            // pq.pop();
        }
        return res;
    }
};