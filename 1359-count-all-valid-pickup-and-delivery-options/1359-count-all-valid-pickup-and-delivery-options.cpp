class Solution {
public:
    int countOrders(int n) {
        long long res=1;
        int mod=1e9+7,x=2*n;
        for(int i=1;i<=n;i++){
            long long tmp=(x*(x-1))/2;
            res*=tmp;
            x-=2;
            res%=mod;
        }
        return res;
    }
};