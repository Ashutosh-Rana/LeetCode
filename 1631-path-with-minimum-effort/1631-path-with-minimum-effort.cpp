class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int m=heights.size(),n=heights[0].size();
        vector<vector<int>> dist(m,vector<int> (n,1e9));
        pq.push({0,{0,0}});
        dist[0][0]=0;
        while(!pq.empty()){
            int r=pq.top().second.first;
            int c=pq.top().second.second;
            int dif=pq.top().first;
            if(r==m-1 && c==n-1){
                return dif;
            }
            pq.pop();
            vector<int> drc={0,1,0,-1,0};
            for(int i=0;i<4;i++){
                int nr=r+drc[i];
                int nc=c+drc[i+1];
                if(nr>=0 && nr<m && nc>=0 && nc<n){
                    int newEffort=max(abs(heights[nr][nc]-heights[r][c]),dif);
                    if(newEffort<dist[nr][nc]){
                        dist[nr][nc]=newEffort;
                        pq.push({dist[nr][nc],{nr,nc}});
                    }   
                }
            }
        }
        return 0;
    }
};                                                                                                  