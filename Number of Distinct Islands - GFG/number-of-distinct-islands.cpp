//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,
    int row0,int col0,vector<pair<int,int>>& vec){
        int r=grid.size(),c=grid[0].size();
        vis[i][j]=1;
        vec.push_back({i-row0,j-col0});
        vector<int> drc={0,1,0,-1,0};
        for(int p=0;p<4;p++){
            int nr=i+drc[p];
            int nc=j+drc[p+1];
            if(nr>=0 && nr<r && nc>=0 && nc<c && !vis[nr][nc] && grid[nr][nc]==1){
                dfs(nr,nc,grid,vis,row0,col0,vec);
            }
        }
    }    
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int r=grid.size(),c=grid[0].size();
        vector<vector<int>> vis(r,vector<int>(c,0));
        set<vector<pair<int,int>>> st;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                vector<pair<int,int>> vec;
                if(!vis[i][j] && grid[i][j]==1){
                    dfs(i,j,grid,vis,i,j,vec);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends