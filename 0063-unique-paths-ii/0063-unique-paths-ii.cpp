class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        vector<vector<int>> dp(m,vector<int> (n,0));
        if(obstacleGrid[0][0]==0){
            dp[0][0]=1;
        }
        else return 0 ;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!i && !j) continue;
                
                if( (i==0 or j==0) && !obstacleGrid[i][j] ){
                    if(i==0){
                        dp[i][j]=dp[i][j-1];
                    }
                    else{
                        dp[i][j]=dp[i-1][j];
                    }
                }
                else if((i && j) && !obstacleGrid[i][j] ){
                    dp[i][j]=dp[i-1][j]+dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1];
    }
};