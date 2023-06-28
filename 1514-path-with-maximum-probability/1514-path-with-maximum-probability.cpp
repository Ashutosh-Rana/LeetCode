class Solution {
  
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int,double>> adj[n];
        // map<pair<int,int>,double> mp;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0],v=edges[i][1];
            // cout<<succProb[i]<<" ";
            adj[u].push_back({v,succProb[i]});
            adj[v].push_back({u,succProb[i]});
        }
        vector<int> vis(n,0);
        double res=0;
        priority_queue<pair<double,int>> pq;
        pq.push({1,start});
        while(!pq.empty()){
            double prob=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(node==end){
                return prob;
            }
            vis[node]=1;
            // cout<<node<<" "<<prob<<endl;
            for(auto it:adj[node]){
                int nei=it.first;
                double adj_prob=it.second;
                // cout<<nei<<" "<<adj_prob<<endl;
                if(!vis[nei]){
                    pq.push({prob*adj_prob,nei});
                    // cout<<prob*adj_prob<<endl;
                }
            }
        }
        return res;
    }
};