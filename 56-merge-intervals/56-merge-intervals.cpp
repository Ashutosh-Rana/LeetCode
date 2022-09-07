class Solution {
// private:
//     bool sortByCol(const vector<int>& v1,const vector<int>& v2){
//         return v1[0]<v2[0];
//     }
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // for(int i=0;i<intervals.size();i++){
        //     for(int j=i+1;j<intervals.size();j++){
        //         if(intervals[i][0]>intervals[j][0]){
        //             swap(intervals[i],intervals[j]);
        //         }
        //     }
        // }
        sort(intervals.begin(),intervals.end());  //this will sort the 2d array according to 0th column
        vector<vector<int>> res;
        int s=intervals[0][0],e=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=e && intervals[i][1]>=e){
                e=intervals[i][1];
            }
            else if(intervals[i][0]<=e && intervals[i][1]<=e){
                continue;
            }
            else{
                vector<int> v={s,e};
                res.push_back(v);
                s=intervals[i][0],e=intervals[i][1];
            }
        }
        vector<int> v={s,e};
        res.push_back(v);
        return res;
    }
};