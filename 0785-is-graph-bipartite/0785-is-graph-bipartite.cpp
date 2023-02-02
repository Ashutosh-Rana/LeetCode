class Solution {
private:
    bool checkBFS(int start,int n,vector<vector<int>>& graph,vector<int>& color){
        queue<int> q;
        q.push(start);
        color[start]=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto it:graph[node]){
                if(color[it]==-1){
                    q.push(it);
                    color[it]=1-color[node];
                }
                else if(color[it]==color[node]){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool checkDFS(int start,int n,vector<vector<int>>& graph,vector<int>& color){
        for(auto it:graph[start]){
            if(color[it]==-1){
                color[it]=1-color[start];
                if(!checkDFS(it,n,graph,color)){
                    return false;
                }
            }
            else if(color[it]==color[start]){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                color[i]=0;
                if(!checkDFS(i,n,graph,color)){
                    return false;
                }
            }
        }
        return true;
    }
};