class Solution {
    int res=0;
private:
    void dfs(int node,int caller,vector<int> adj[],
             map<pair<int,int>,int> &mp,vector<int> &vis){
        vis[node]=1;
        if(caller!=-1){
            if(!mp[{node,caller}]){
                res++;
            } 
        }
        for(int adj_node:adj[node]){
            if(!vis[adj_node]){
                dfs(adj_node,node,adj,mp,vis);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        int m=connections.size();
        vector<int> adj[n],vis(n,0);
        map<pair<int,int>,int> mp;
        for(int i=0;i<m;i++){
            int u=connections[i][0],v=connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            mp[{u,v}]=1;
        }
        dfs(0,-1,adj,mp,vis);
        return res;
    }
};