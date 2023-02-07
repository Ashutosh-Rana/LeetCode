class Solution {
private:
    bool dfsCycle(int node,vector<int>& vis,vector<int>& pathVis,vector<int> adj[]){
        vis[node]=1;
        pathVis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfsCycle(it,vis,pathVis,adj)==true){
                    return true;
                }
            }
            else if(pathVis[it]){
                return true;
            }
        }
        pathVis[node]=0;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        int n=prerequisites.size();
        for(int i=0;i<n;i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        vector<int> vis(numCourses,0),pathVis(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(!vis[i]){
                if(dfsCycle(i,vis,pathVis,adj)==true){
                    return false;
                }
            }
        }
        return true;
    }
};