class Solution {
private: 
    void dfs(int node,vector<pair<int,int>> adj[],vector<int> &vis){
    // if(vis[node]){
    //     return;
    // }
    vis[node]=1;
    for(auto it:adj[node]){
        int dest=it.first,d=it.second;
        
        if(!vis[dest]){
            // cout<<node<<" "<<dest<<" "<<d<<endl;
            // res=min(res,d);
            dfs(dest,adj,vis);
        }
    }
}
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n+1];
        for(auto it:roads){
            // cout<<it[0]<<" "<<it[1]<<endl;
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        // cout<<adj[1][0];
        // for(auto it:adj[2]){
        //     int a=it.first,b=it.second;
        //     cout<<a<<" "<<b<<endl;
        // }
        int res=INT_MAX;
        // int res=0;
        vector<int> vis(n+1,0);
        dfs(1,adj,vis);
        
        for(auto it:roads){
            if(vis[it[0]] && vis[it[1]] && it[2]<res){
                res=it[2];
            }
        }
        return res;
    }
};