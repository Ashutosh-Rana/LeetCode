class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int r=grid.size(),c=grid[0].size(),i=r-1,j=0,cnt=0;
        while(i>=0 && j<c){
            if(grid[i][j]<0){
                cnt+=c-j;
                i--;
            }
            else{
                j++;
            }
        }
        return cnt;
    }
};