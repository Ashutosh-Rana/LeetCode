class Solution {
// private:
//     void bfs(int r,int c,vector<vector<int>>& mat){
//         int m=mat.size(),n=mat[0].size();
//         queue<pair<int,int>> q;
//         q.push({r,c});
//         vector<vector<int>> vis(m,vector<int> (n,0));
//         vis[r][c]=1;
//         int cnt=0;
//         while(!q.empty()){
//             cnt++;
//             int nr=q.front().first;
//             int nc=q.front().second;
//             q.pop();
//             vector<int> dr={-1,0,1,0};
//             vector<int> dc={0,1,0,-1};
//             for(int i=0;i<4;i++){
//                 int newR=nr+dr[i];
//                 int newC=nc+dc[i];
//                 if(newR>=0 && newR<m && newC>=0 && newC<n &&
//                    !vis[newR][newC] && mat[newR][newC]==0){
//                     while(!q.empty()){
//                         q.pop();
//                     }
//                     break;
//                 }
//                 else if(newR>=0 && newR<m && newC>=0 && newC<n &&
//                    !vis[newR][newC] && mat[newR][newC]!=0){
//                     vis[newR][newC]=1;
//                     q.push({newR,newC});
//                 }
//             }
//         }
//         mat[r][c]=cnt;
//     }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> vis(m,vector<int> (n,0));
        vector<vector<int>> dist(m,vector<int> (n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int steps=q.front().second;
            q.pop();
            dist[r][c]=steps;
            vector<int> dr={-1,0,1,0};
            vector<int> dc={0,1,0,-1};
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc]){
                    vis[nr][nc]=1;
                    q.push({{nr,nc},steps+1});
                }
            }
        }
        return dist;
    }
};