class Solution {
public:
    typedef pair<int,vector<int>> pi;
    
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        for(vector<int> p:points){
            int d=(p[0]*p[0])+(p[1]*p[1]);
            pq.push(make_pair(d,p));
        }
        vector<vector<int>> res(k);
        for(int i=0;i<k;i++){
            auto tp=pq.top();
            pq.pop();
            res[i]=tp.second;
        }
        return res;
    }
};