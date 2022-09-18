class Solution {
public:
    bool isPerfectSquare(int num) {
        double d=sqrt(num);
        d*=100;
        int r=(int)d%100;
        if(r==0){
            return true;
        }
        return false;
    }
};