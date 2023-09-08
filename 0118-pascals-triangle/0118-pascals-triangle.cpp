class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows);
        res[0].push_back(1);
        int cnt=1;
        for(int i=1;i<numRows;i++){
            res[i].push_back(1);
            cnt++;
            for(int j=1;j<cnt-1;j++){
                res[i].push_back(res[i-1][j-1]+res[i-1][j]);
            }
            res[i].push_back(1);
        }
        return res;
    }
};