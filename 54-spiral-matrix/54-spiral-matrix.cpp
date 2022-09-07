class Solution {
public:
    
    void calSpiral(vector<int> &res,int cnt,vector<vector<int>>& matrix){
        
        int Col=matrix[0].size(),Row=matrix.size(),i;
        if(res.size()==Col*Row){
            return;
        }
        for(i=cnt;i<Col-cnt;i++){
            res.push_back(matrix[cnt][i]);
        }
        if(res.size()==Col*Row){
            return;
        }
        //Col=i--;
        for(i=cnt+1;i<Row-cnt;i++){
            res.push_back(matrix[i][Col-cnt-1]);
        }
        if(res.size()==Col*Row){
            return;
        }
        //Row=i--;
        for(i=Col-cnt-2;i>=cnt;i--){
            res.push_back(matrix[Row-cnt-1][i]);
        }
        if(res.size()==Col*Row){
            return;
        }
        for(i=Row-cnt-2;i>=cnt+1;i--){
            res.push_back(matrix[i][cnt]);
        }
        cnt++;
        calSpiral(res,cnt,matrix);
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        calSpiral(res,0,matrix);
        return res;
    }
};