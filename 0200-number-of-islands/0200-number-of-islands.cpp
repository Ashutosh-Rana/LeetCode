class Solution {
public:
    void bfs(int r,int c,vector<vector<int>>& vis,vector<vector<char>>& grid){
        queue<pair<int,int>> q;
        q.push({r,c});
        vis[r][c]=1;
        int n=grid.size(),m=grid[0].size();
        // int newR=r,newC=c;
        while(!q.empty()){
            int newR=q.front().first;
            int newC=q.front().second;
            q.pop();
            for(int nr=-1;nr<=1;nr++){
                for(int nc=-1;nc<=1;nc++){
                    if(newR+nr>=0 && newR+nr<n && newC+nc>=0 && newC+nc<m && abs(nr)!=abs(nc)
                       && !vis[newR+nr][newC+nc] && grid[newR+nr][newC+nc]=='1'){
                        // newR=newR+nr;
                        // newC+=nc;
                        vis[newR+nr][newC+nc]=1;
                        q.push({newR+nr,newC+nc});
                    }
                }
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        //queue<pair<int,int>> q;
        int cnt=0;
        for(int r=0;r<n;r++){
            for(int c=0;c<m;c++){
                if(grid[r][c]=='1' && !vis[r][c]){
                    
                    bfs(r,c,vis,grid);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};