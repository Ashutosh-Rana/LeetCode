// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int m=grid.size(),n=grid[0].size();
//         int vis[m][n];
//         queue<pair<pair<int,int>,int>> q;
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]==2){
//                     q.push({{i,j},0});
//                     vis[i][j]=2;
//                 }
//             }
//         }
//         int t=0;
//         while(!q.empty()){
//             int r=q.front().first.first;
//             int c=q.front().first.second;
//              t=q.front().second;
//             q.pop();
//             //tm=max(tm,t);
//             vector<int> dr={-1,0,+1,0};
//             vector<int> dc={0,+1,0,-1};
//             for(int i=0;i<4;i++){
//                 int nr=r+dr[i],nc=c+dc[i];
//                 if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]!=2 && grid[nr][nc]==1){
//                     q.push({{nr,nc},t+1});
//                     vis[nr][nc]=2;
//                 }
//             }
//         }
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(grid[i][j]==1 && vis[i][j]!=2){
//                     return -1;
//                 }
//             }
//         }
//         return t;
        
//     }
// };

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) 
    {
        
        vector<int> dir={-1,0,1,0,-1}; //used for finding all 4 adjacent coordinates
        
        int m=grid.size();
        int n=grid[0].size();
        
        queue<pair<int,int>> q;
        int fresh=0; //To keep track of all fresh oranges left
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j]==1)
                    fresh++;
            }
        int ans=-1; //initialised to -1 since after each step we increment the time by 1 and initially all rotten oranges started at 0.
        while(!q.empty())
        {
            int sz=q.size();
            while(sz--)
            {
                pair<int,int> p=q.front();
                q.pop();
                for(int i=0;i<4;i++)
                {
                    int r=p.first+dir[i];
                    int c=p.second+dir[i+1];
                    if(r>=0 && r<m && c>=0 && c<n &&grid[r][c]==1)
                    {
                        grid[r][c]=2;
                        q.push({r,c});
                        fresh--; // decrement by 1 foreach fresh orange that now is rotten
                    }
                    
                }
            }
            ans++; //incremented after each minute passes
        }
        if(fresh>0) return -1; //if fresh>0 that means there are fresh oranges left
        if(ans==-1) return 0; //we initialised with -1, so if there were no oranges it'd take 0 mins.
        return ans;
        
    }
};