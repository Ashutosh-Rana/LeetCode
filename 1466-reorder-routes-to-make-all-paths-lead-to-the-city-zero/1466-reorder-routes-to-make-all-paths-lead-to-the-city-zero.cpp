class Solution {
    int res=0;
private:
    void dfs(int node,vector<int> adj[],
             map<pair<int,int>,int> &mp,vector<int> &vis){
        vis[node]=1;
        for(int adj_node:adj[node]){
            if(!vis[adj_node]){
                if(mp[{node,adj_node}]) res++;
                dfs(adj_node,adj,mp,vis);
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
        dfs(0,adj,mp,vis);
        return res;
    }
};