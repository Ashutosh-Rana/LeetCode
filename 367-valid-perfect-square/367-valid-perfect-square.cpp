class Solution {
public:
    bool isPerfectSquare(int num) {
        // double d=sqrt(num);
        // d*=100;
        // int r=(int)d%100;
        // if(r==0){
        //     return true;
        // }
        // return false;
        
        int i=1;
        while(num>0){
            num-=i;
            i+=2;
            if(!num){
                return true;
            }
        }
        return false;
    }
};