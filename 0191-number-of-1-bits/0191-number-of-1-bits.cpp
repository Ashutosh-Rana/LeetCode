class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt=0;
        while(n){
            // if(n&1==1){
            //     cnt++;
            // } or
            if(n%2==1){
                cnt++;
            }
            n=n>>1;//right shift
        }
        
        return cnt;
    }
};