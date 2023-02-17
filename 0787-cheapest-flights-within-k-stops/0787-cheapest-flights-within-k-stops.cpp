class Solution {
 
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int r=flights.size();
        vector<pair<int,int>> adj[n];
        for(int i=0;i<r;i++){
            int u=flights[i][0],v=flights[i][1],wt=flights[i][2];
            adj[u].push_back({v,wt});
        }
        // for(int i=0;i<n;i++){
        //     for(auto it:adj[i]){
        //         cout<<i<<" "<<it.first<<" "<<it.second<<endl;
        //     }
        // }
        vector<int> dist(n,1e9);
        dist[src]=0;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        while(!q.empty()){
            int stops=q.front().first;
            int node=q.front().second.first;
            int dis=q.front().second.second;
            q.pop();
            if(stops>k){
                continue;
            }
            for(auto it:adj[node]){
                int adj_node=it.first;
                int adj_wt=it.second;
                if(dis+adj_wt<dist[adj_node] && stops<=k){
                    dist[adj_node]=dis+adj_wt;
                    q.push({stops+1,{adj_node,dist[adj_node]}});
                }
            }
        }
        if(dist[dst]!=1e9){
            return dist[dst];
        }
        return -1;
    }
};