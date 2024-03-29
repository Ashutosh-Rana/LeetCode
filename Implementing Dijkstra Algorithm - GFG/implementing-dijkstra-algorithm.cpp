//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // vector<int> dist(V,1e9);
        // dist[S]=0;
        // pq.push({0,S});
        // while(!pq.empty()){
        //     int node=pq.top().second;
        //     //int wt=pq.top().first;
        //     pq.pop();
        //     for(auto it:adj[node]){
        //         int adj_node=it[0];
        //         int adj_wt=it[1];
        //         if(dist[node]+adj_wt<dist[adj_node]){
        //             dist[adj_node]=dist[node]+adj_wt;
        //             pq.push({adj_wt,adj_node});
        //         }
        //     }
        // }
        
        set<pair<int,int>> st;
        vector<int> dist(V,1e9);
        dist[S]=0;
        st.insert({0,S});
        while(!st.empty()){
            auto it=*(st.begin());
            int node=it.second;
            int dis=it.first;
            st.erase(it);
            for(auto i:adj[node]){
                int adj_node=i[0];
                int wt=i[1];
                if(dist[node]+wt<dist[adj_node]){
                    if(dist[adj_node]!=1e9){
                        st.erase({dist[adj_node],adj_node});
                    }
                    dist[adj_node]=dist[node]+wt;
                    st.insert({dist[adj_node],adj_node});
                }
            }
        }
        
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends