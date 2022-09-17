class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r=matrix.size(),c=matrix[0].size();
        int i=0,j=c-1;
        while(i<r && j>=0){
            if(target==matrix[i][j]){
                return true;
            }
            if(target>matrix[i][j]){
                i++;
            }
            else{
                j--;
            }
        }
        return false;
        
        // for(int i=0;i<r;i++){
        //     if(target>=matrix[i][0] && target<=matrix[i][c-1]){
        //         int l=0,rt=c-1;
        //         while(l<=rt){
        //             int mid=(l+rt)/2;
        //             if(target==matrix[i][mid]){
        //                 return true;
        //             }
        //             if(target>matrix[i][mid]){
        //                 l=mid+1;
        //             }
        //             else{
        //                 rt=mid-1;
        //             }
        //         }
        //     }
        // }
        // return false;
    }
};