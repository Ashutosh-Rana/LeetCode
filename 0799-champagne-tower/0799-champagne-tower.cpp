class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> cur_row(1,poured);
        for(int i=0;i<=query_row;i++){
            vector<double> next_row(i+2,0);
            for(int j=0;j<=i;j++){
                if(cur_row[j]>1){
                    next_row[j]+=(cur_row[j]-1)/2.0;
                    next_row[j+1]+=(cur_row[j]-1)/2.0;
                    cur_row[j]=1;
                }
            }
            if(i!=query_row) cur_row=next_row;
        }
        return cur_row[query_glass];
    }
};