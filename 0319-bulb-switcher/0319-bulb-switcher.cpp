class Solution {
public:
    int bulbSwitch(int n) {
        if(!n){
            return 0;
        }
        int res=floor(sqrt(n));
        return res;
    }
};