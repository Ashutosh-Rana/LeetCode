class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> g(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                g[j][i]=grid[i][j];
            }
        }
        int res=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i]==g[j]){
                    res++;
                    // break;
                }
            }
        }
        return res;
    }
};