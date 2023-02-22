class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        // cout<<intervals[1][0]<<intervals[1][1];
        int start=intervals[0][0],end=intervals[0][1],cnt=0,n=intervals.size();
        for(int i=1;i<n;i++){
            if(intervals[i][0]<end){
                cnt++;
                if(end>intervals[i][1]){
                    start=intervals[i][0],end=intervals[i][1];
                }
            }
            else{
                start=intervals[i][0],end=intervals[i][1];
            }
        }
        return cnt;
    }
};