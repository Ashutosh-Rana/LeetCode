class Solution {
private:
    bool bfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int i,int j){
        queue<pair<int,int>> q;
        int m=grid.size(),n=grid[0].size();
        bool res=true;
        q.push({i,j});
        vis[i][j]=1;
        while(!q.empty()){
            int r=q.front().first,c=q.front().second;
            q.pop();
            vector<int> p={-1,0,1,0,-1};
            for(int i=0;i<4;i++){
                int nr=r+p[i],nc=c+p[i+1];
                if(nr>=0 && nr<=m-1 && nc>=0 && nc<=n-1 && (nr==0 || nr==m-1 || nc==0 || nc==n-1) && grid[nr][nc]==0 ){
                    res=false;
                }
                else if(nr>0 && nr<m-1 && nc>0 && nc<n-1 && !vis[nr][nc] && grid[nr][nc]==0){
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        return res;
    }
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size(),cnt=0;
        vector<vector<int>> vis(m,vector<int> (n,0));
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(grid[i][j]==0 && !vis[i][j]){
                    if(bfs(grid,vis,i,j)){
                        cout<<i<<" "<<j<<endl;
                        cnt++;
                    }
                    else{
                        continue;
                    }
                }
            }
        }
        return cnt;
    }
};