#define ll long long

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,long long>> adj[n];
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> pq;
        vector<int> count(n,0);
        vector<long long> dist(n,LONG_MAX);
        pq.push({0,0});
        count[0]=1;
        dist[0]=0;
        int mod=(1e9+7);
        while(!pq.empty()){
            long long  dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            //cout<<dis<<" "<<node<<endl;
            // if(node==n-1){
            //     continue;
            // }
            if(dis<dist[node]){
                continue;
            }
            for(auto it:adj[node]){
                int adj_node=it.first;
                long long adj_wt=it.second;
                if(dis+adj_wt<dist[adj_node]){
                    dist[adj_node]=dis+adj_wt;
                    pq.push({dis+adj_wt,adj_node});
                    count[adj_node]=count[node];
                }
                else if(dis+adj_wt==dist[adj_node] ){
                    count[adj_node]=(count[adj_node]+count[node])%mod;
                    
                }
                //cout<<node<<" "<<adj_node<<" "<<count[adj_node]<<endl;
            }
        }
        
        return count[n-1];
    }
};