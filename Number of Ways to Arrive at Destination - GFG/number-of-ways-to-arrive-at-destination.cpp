//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>> adj[n];
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> count(n,0);
        vector<int> dist(n,1e9);
        pq.push({0,0});
        count[0]=1;
        dist[0]=0;
        int mod=int(pow(10,9)+7);
        while(!pq.empty()){
            int dis=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            //cout<<dis<<" "<<node<<endl;
            // if(node==n-1){
            //     continue;
            // }
            for(auto it:adj[node]){
                int adj_node=it.first;
                int adj_wt=it.second;
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

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends