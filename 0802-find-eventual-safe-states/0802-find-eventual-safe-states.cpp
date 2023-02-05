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
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> vis(V,0),pathVis(V,0),check(V,0),safe_nodes;
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfsCheck(i,vis,pathVis,check,graph);
            }
        }
        for(int i=0;i<V;i++){
            if(check[i]){
                safe_nodes.push_back(i);
            }
        }
        return safe_nodes;
    }
};