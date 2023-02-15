//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        queue<pair<int,int>> q;
        // vector<pair<pair<int,int>>,int> dist;
        
        int m=grid.size(),n=grid[0].size();
        //int dist[m][n]={1e9};
        vector<vector<int>> dist(m,vector<int> (n,1e9));
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         dist[{i,j}]=1e9;
        //     }
        // }
        q.push({source.first,source.second});
        dist[source.first][source.second]=0;
        while(!q.empty()){
            int r=q.front().first,c=q.front().second;
            q.pop();
            vector<int> drc={0,1,0,-1,0};
            for(int i=0;i<4;i++){
                int nr=r+drc[i],nc=c+drc[i+1];
                if(nr>=0 && nr<m && nc>=0 && nc<n && grid[nr][nc]==1 && 
                dist[r][c]+1< dist[nr][nc]){
                    dist[nr][nc]=dist[r][c]+1;
                    q.push({nr,nc});
                }
            }
        }
        int d_r=destination.first,d_c=destination.second;
        if(dist[d_r][d_c]==1e9){
            return -1;
        }
        return dist[d_r][d_c];
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

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends