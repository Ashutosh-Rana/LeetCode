class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int y=(coordinates[1][1]-coordinates[0][1]);
        float x=(coordinates[1][0]-coordinates[0][0]);
        float slope=y/x;
        int flag=0;
        if(x==0){
            flag=1;
        }
        // cout<<slope;
        for(int i=2;i<coordinates.size();i++){
            int y2=(coordinates[i][1]-coordinates[0][1]);
            float x2=(coordinates[i][0]-coordinates[0][0]);
            if(flag==1 && x2==0){
                continue;
            }
            float temp=y2/x2;
            if(slope==temp){
                continue;
            }
            return false;
        }      
        return true;
    }
};