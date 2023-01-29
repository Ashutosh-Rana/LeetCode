class Solution {
private:
    void dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,int i,int j){
        int r=grid.size(),c=grid[0].size();
        vis[i][j]=1;
        vector<int> drc={0,1,0,-1,0};
        for(int p=0;p<4;p++){
            int nr=i+drc[p];
            int nc=j+drc[p+1];
            if(nr>=0 && nr<r && nc>=0 && nc<c && !vis[nr][nc] && grid[nr][nc]==1){
                dfs(grid,vis,nr,nc);
            }
        }
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size();
        vector<vector<int>> vis(r,vector<int>(c,0));
        for(int i=0;i<c;i++){
            if(!vis[0][i] && grid[0][i]==1){
                dfs(grid,vis,0,i);
            }
            if(!vis[r-1][i] && grid[r-1][i]==1){
                dfs(grid,vis,r-1,i);
            }
        }
        for(int i=0;i<r;i++){
            if(!vis[i][0] && grid[i][0]==1){
                dfs(grid,vis,i,0);
            }
            if(!vis[i][c-1] && grid[i][c-1]==1){
                dfs(grid,vis,i,c-1);
            }
        }
        int cnt=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};