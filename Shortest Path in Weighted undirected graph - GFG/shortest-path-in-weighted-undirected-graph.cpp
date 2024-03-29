//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<m;i++){
            int u=edges[i][0],v=edges[i][1],wt=edges[i][2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,1e9),parent(n+1);
        for(int i=1;i<n+1;i++){
            parent[i]=i;
        }
        dist[1]=0;
        pq.push({0,1});
        while(!pq.empty()){
            int node=pq.top().second;
            pq.pop();
            for(auto i:adj[node]){
                int adj_node=i.first;
                int wt=i.second;
                if(dist[node]+wt<dist[adj_node]){
                    dist[adj_node]=dist[node]+wt;
                    parent[adj_node]=node;
                    pq.push({dist[adj_node],adj_node});
                }
            }
        }
        int node=n;
        vector<int> res;
        while(parent[node]!=node){
            res.push_back(node);
            node=parent[node];
        }
        res.push_back(1);
        reverse(res.begin(),res.end());
        if(res[0]==1 && res[res.size()-1]==n){
            return res;
        }
        // return res;
        return {-1};
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends