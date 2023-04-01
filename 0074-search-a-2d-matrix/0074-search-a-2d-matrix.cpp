class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l_row=0,r_row=matrix.size()-1,m=matrix.size(),n=matrix[0].size();
        while(l_row<=r_row){
            int mid_row=l_row+(r_row-l_row)/2;
            if(target<matrix[mid_row][0]){
                r_row=mid_row-1;
            }
            else if(target>matrix[mid_row][n-1]){
                l_row=mid_row+1;
            }
            else{
                int l=0,r=n-1;
                while(l<=r){
                    int mid=l+(r-l)/2;
                    if(target>matrix[mid_row][mid]){
                        l=mid+1;
                    }
                    else if(target<matrix[mid_row][mid]){
                        r=mid-1;
                    }
                    else{
                        return true;
                    }
                }
                return false;
            }
        }
        return false;
    }
};