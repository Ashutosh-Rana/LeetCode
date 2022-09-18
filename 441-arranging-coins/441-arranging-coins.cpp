class Solution {
public:
    int arrangeCoins(int n) {
        unsigned i=1,sum=0;
        while(sum<n){
            sum+=i;
            i++;
        }
        if(sum>n){
            return i-2;
        }
        return i-1;
        
    }
};