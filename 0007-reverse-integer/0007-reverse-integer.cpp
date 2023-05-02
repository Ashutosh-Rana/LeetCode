class Solution {
public:
    int reverse(int x) {
        int minm=INT_MIN,maxm=INT_MAX;
        int res=0;
        while(x){
            int digit=x%10;
            x/=10;
            if(res>maxm/10 or (res==maxm/10 && digit>maxm%10)){
                return 0;
            }
            if(res<minm/10 or (res==minm/10 && digit<minm%10)){
                return 0;
            }
            res=res*10+digit;
        }
        return res;
    }
};