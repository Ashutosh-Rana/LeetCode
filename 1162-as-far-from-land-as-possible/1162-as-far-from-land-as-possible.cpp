class Solution {
// private:   TLE
//     int bfs(int row,int col,vector<vector<int>>& grid){
//         queue<pair<int,int>> q;
//         int n=grid.size();
//         vector<vector<int>> vis(n,vector<int> (n,0));
        
//         q.push({row,col});
//         while(!q.empty()){
//             int r=q.front().first,c=q.front().second;
//             q.pop();
//             vis[r][c]=1;
//             vector<int> drc={0,1,0,-1,0};
//             for(int p=0;p<4;p++){
//                 int nr=r+drc[p],nc=c+drc[p+1];
//                 if(nr>=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]==1){
//                     //cout<<row<<" "<<col<<" "<<nr<<" "<<nc<<" "<<abs(nr-row)+abs(nc-col)<<endl;
//                     return abs(nr-row)+abs(nc-col);
//                 }
//                 else if( nr>=0 && nr<n && nc>=0 && nc<n && !vis[nr][nc] && grid[nr][nc]==0){
//                     q.push({nr,nc});
//                 }
//             }
//         }
//         return -1;
//     }
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size(),steps=1;
        queue<pair<int,int>> q,q1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j+1});
                    q.push({i+1,j});
                    q.push({i,j-1});
                    q.push({i-1,j});
                }
            }
        }
        while(!q.empty()){
            steps++;
            while(!q.empty()){
                int r=q.front().first,c=q.front().second;
                q.pop();
                if(r>=0 && r<n && c>=0 && c<n && grid[r][c]==0){
                    grid[r][c]=steps;
                    //cout<<r<<" "<<c<<" "<<steps<<endl;
                    q1.push({r,c+1});
                    q1.push({r+1,c});
                    q1.push({r,c-1});
                    q1.push({r-1,c});
                    
                }
            }
            swap(q1,q);
        }
        if(steps==2 || steps==1){
            return -1;
        }
        return steps-2;
    }
};