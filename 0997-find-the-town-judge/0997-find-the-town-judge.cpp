class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1){
            return 1;
        }
        vector<int> adj[n+1];
        for(int i=0;i<trust.size();i++){
            adj[trust[i][0]].push_back(trust[i][1]);
        }
        int center_node,cnt=0;
        for(int i=1;i<=n;i++){
            if(adj[i].size()==0){
                center_node=i;
                cnt++;
                if(cnt>1){
                    return -1;
                }
            }
        }
        if(cnt==0){
            return -1;
        }
        int cnt_people=0;
        vector<bool> vis(n+1);
        for(int i=0;i<trust.size();i++){
            if(trust[i][1]==center_node && !vis[trust[i][0]]){
                vis[trust[i][0]]=true;
                cnt_people++;
                if(cnt_people==n-1){
                    return center_node;
                }
            }
        }
        return -1;
    }
};