class Solution {
private:
    void dfs(int i,int j,vector<vector<char>>& board,vector<vector<int>>& vis){
        int m=board.size(),n=board[0].size();
        vis[i][j]=1;
        vector<int> drc={0,1,0,-1,0};
        for(int p=0;p<4;p++){
            int nr=i+drc[p];
            int nc=j+drc[p+1];
            if(nr>=0 && nr<m && nc>=0 && nc<n && !vis[nr][nc] && board[nr][nc]=='O'){
                dfs(nr,nc,board,vis);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            if(!vis[0][i] && board[0][i]=='O'){
                dfs(0,i,board,vis);
            }
            
            if(!vis[m-1][i] && board[m-1][i]=='O'){
                dfs(m-1,i,board,vis);
            }
        }
       
        for(int i=0;i<m;i++){
            if(!vis[i][0] && board[i][0]=='O'){
                dfs(i,0,board,vis);
            }
            
            if(!vis[i][n-1] && board[i][n-1]=='O'){
                dfs(i,n-1,board,vis);
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};