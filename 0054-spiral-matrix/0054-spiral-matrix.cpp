class Solution {
    vector<int> res;
private:
    void helper(int cnt,vector<vector<int>>& matrix){
        int m=matrix.size(),n=matrix[0].size();
        for(int i=cnt;i<n-cnt;i++){
            res.push_back(matrix[cnt][i]);
            cout<<matrix[cnt][i]<<" ";
        }
        if(res.size()==m*n){
            return;
        }
        for(int i=cnt+1;i<m-cnt;i++){
            res.push_back(matrix[i][n-1-cnt]);
            cout<<matrix[i][n-1-cnt]<<" ";
        }
        if(res.size()==m*n){
            return;
        }
        for(int i=n-2-cnt;i>=cnt;i--){
            res.push_back(matrix[m-1-cnt][i]);
            cout<<matrix[m-1-cnt][i]<<" ";
        }
        if(res.size()==m*n){
            return;
        }
        for(int i=m-2-cnt;i>=cnt+1;i--){
            res.push_back(matrix[i][cnt]);
            cout<<matrix[i][cnt]<<" ";
        }
    }
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size(),cnt=0;
        while(res.size()!=m*n){
            helper(cnt,matrix);
            cnt++;
        }
        return res;
    }
};