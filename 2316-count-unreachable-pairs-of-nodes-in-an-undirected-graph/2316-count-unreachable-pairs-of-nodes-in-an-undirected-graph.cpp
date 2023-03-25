#define ll long long
class Solution {
private:
    void dfs(int node,long long &cnt,vector<int>& vis,vector<int> adj[]){
        if(vis[node]){
            return;
        }
        vis[node]=1;
        cnt++;
        for(auto it:adj[node]){
            if(!vis[it]){
                // vis[it]=1;
                // cnt++;
                dfs(it,cnt,vis,adj);
            }
        }
    }
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        // if(edges.size()==0){
        //     long long a=n;
        //     long long res=((a*(a-1))/2);
        //     return res;
        // }
        long long cnt;
        vector<int> vis(n,0);
        vector<long long> v;
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        long long res=((ll)n*(n-1))/2;
        for(int i=0;i<n;i++){
            cnt=0;
            if(!vis[i]){
                dfs(i,cnt,vis,adj);
                res-=(cnt*(cnt-1))/2;
                // v.push_back(cnt);
                // cout<<cnt<<endl;
            }
        }
        
        // for(int i=0;i<v.size();i++){
        //     for(int j=i+1;j<v.size();j++){
        //         res+=v[i]*v[j];
        //     }
        // }
        return res;
    }
};