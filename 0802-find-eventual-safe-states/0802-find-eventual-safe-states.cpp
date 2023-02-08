class Solution {
private: 
    bool dfsCheck(int node,vector<int>& vis,vector<int>& pathVis,vector<int>& check,vector<vector<int>>& graph){
    vis[node]=1;
    pathVis[node]=1;
    for(auto it:graph[node]){
        if(!vis[it]){
            if(dfsCheck(it,vis,pathVis,check,graph)){
                return true;
            }
        }
        else if(pathVis[it]){
            return true;
        }
    }
    pathVis[node]=0;
    check[node]=1;
    return false;
}
    
void bfsCheck(queue<int>& q,vector<int> graph_rev[],vector<int> indegree,vector<int>& res){
    while(!q.empty()){
        int node=q.front();
        res.push_back(node);
        q.pop();
        for(auto it:graph_rev[node]){
            indegree[it]--;
            if(!indegree[it]){
                q.push(it);
            }
        }
    }
}
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        // vector<int> vis(V,0),pathVis(V,0),check(V,0),safe_nodes;
        // for(int i=0;i<V;i++){
        //     if(!vis[i]){
        //         dfsCheck(i,vis,pathVis,check,graph);
        //     }
        // }
        // for(int i=0;i<V;i++){
        //     if(check[i]){
        //         safe_nodes.push_back(i);
        //     }
        // }
        // return safe_nodes;
        queue<int> q;
        vector<int> res,graph_rev[V],indegree(V,0);
        for(int i=0;i<V;i++){
            for(auto it:graph[i]){
                graph_rev[it].push_back(i);
                indegree[i]++;
            }
        }
        for(int i=0;i<V;i++){
            if(!indegree[i]){
                q.push(i);
            }
        }
        bfsCheck(q,graph_rev,indegree,res);
        sort(res.begin(),res.end());
        return res;
    }
};