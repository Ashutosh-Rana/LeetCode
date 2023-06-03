class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            if(i!=headID){
                adj[manager[i]].push_back(i);
            }
        }
        queue<pair<int,int>> q;
        int res=0;
        q.push({headID,0});
        while(!q.empty()){
            int id=q.front().first,time=q.front().second;
            q.pop();
            res=max(res,time);
            for(auto it:adj[id]){
                q.push({it,time+informTime[id]});
            }
        }
        return res;
    }
};