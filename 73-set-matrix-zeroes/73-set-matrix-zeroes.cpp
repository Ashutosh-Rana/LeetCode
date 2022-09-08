class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r=matrix.size(),c=matrix[0].size();
        bool first_row_zero=false;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    if(i>0){
                        matrix[i][0]=0;
                    }
                    else{
                        first_row_zero=true;
                    }
                }
            }
        }
        for(int i=1;i<r;i++){   //making rows zero
            if(matrix[i][0]==0){
                for(int j=0;j<c;j++){
                    matrix[i][j]=0;
                }
            }
        }
        for(int i=0;i<c;i++){        //making columns zero
            if(matrix[0][i]==0){
                for(int j=0;j<r;j++){
                    matrix[j][i]=0;
                }
            }
        }
        if(first_row_zero){
            for(int i=0;i<c;i++){
                matrix[0][i]=0;
            }
        }
    }
};