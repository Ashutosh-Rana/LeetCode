class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> adj[n];
        int res=0,m=roads.size();
        for(int i=0;i<m;i++){
            int u=roads[i][0],v=roads[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int u=i,v=j;
                int vis[n][n],tmp=0;
                memset(vis,0,sizeof(vis));
                for(int p=0;p<adj[u].size();p++){
                    int node=adj[u][p];
                    vis[u][node]=1;
                    vis[node][u]=1;
                    tmp++;
                }
                for(int p=0;p<adj[v].size();p++){
                    int node=adj[v][p];
                    if(!vis[v][node]){
                        tmp++;
                    }
                }
                res=max(res,tmp);
            }
            
        }
        return res;
    }
};