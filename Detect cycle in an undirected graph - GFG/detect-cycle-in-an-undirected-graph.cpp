//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    private:
        bool detectCycle_DFS(int node,int parent,int V, vector<int> adj[],vector<int>& vis){
            vis[node]=1;
            for(auto adjacentNode: adj[node]){
                    if(!vis[adjacentNode]){
                        //vis[adjacentNode]=1;
                        if(detectCycle_DFS(adjacentNode,node,V,adj,vis)==true){
                            return true;
                        }
                    }
                    else if(parent!=adjacentNode){
                        return true;
                    }
            }
            
            return false;
        }
        
        bool detectCycle_BFS(int src,int V, vector<int> adj[],vector<int>& vis){
            queue<pair<int,int>> q;
            //vector<int> vis(V,0);
            q.push({src,-1});
            vis[src]=1;
            while(!q.empty()){
                int node=q.front().first;
                int parent=q.front().second;
                q.pop();
                for(auto adjacentNode: adj[node]){
                    if(!vis[adjacentNode]){
                        vis[adjacentNode]=1;
                        q.push({adjacentNode,node});
                    }
                    else if(parent!=adjacentNode){
                        return true;
                    }
                }
            }
            return false;
        }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V,0);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detectCycle_DFS(i,-1,V,adj,vis)){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends