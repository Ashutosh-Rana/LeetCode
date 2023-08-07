class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(),n=matrix[0].size(),l=0,r=m-1,mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid][n-1]){
                break;
            }
            else if(target>matrix[mid][n-1]){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        l=0,r=n-1;
        int mid2;
        while(l<=r){
            mid2=l+(r-l)/2;
            if(target==matrix[mid][mid2]){
                return true;
            }
            if(target>matrix[mid][mid2]){
                l=mid2+1;
            }
            else{
                r=mid2-1;
            }
        }
        return false;
    }
};