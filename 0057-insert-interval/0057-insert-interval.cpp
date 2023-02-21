class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n=intervals.size(),flag=0,i;
        for(i=0;i<n;i++){
            if(newInterval[1]<intervals[i][0]){
                res.push_back(newInterval);
                flag=1;
                break;
            }
            else if(newInterval[0]>intervals[i][1]){
                res.push_back(intervals[i]);
            }
            else{
                newInterval[0]=min(newInterval[0],intervals[i][0]);
                newInterval[1]=max(newInterval[1],intervals[i][1]);
            }
            //flag=0;
        }
        if(!flag){
            res.push_back(newInterval);
            return res;
        }
        for(int j=i;j<n;j++){
            res.push_back(intervals[j]);
        }
        return res;
    }
};