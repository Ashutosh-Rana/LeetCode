class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(n==1 || source==destination){
            return true;
        }
        queue<int> q;
        vector<bool> vis(n);
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        q.push(source);
        vis[source]=true;
        while(!q.empty()){
            int top_ele=q.front();
            q.pop();
            
            for(auto it:adj[top_ele]){
                if(!vis[it]){
                    if(it==destination){
                        return true;
                    }
                    cout<<it<<endl;
                    vis[it]=true;
                    q.push(it);
                }
            }
        }
        return false;
    }
};