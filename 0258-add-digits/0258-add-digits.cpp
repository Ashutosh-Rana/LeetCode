class Solution {
public:
    int addDigits(int num) {
        int res=0;
        while(num){
            res+=num%10;
            if(res/10){
                int ans=0;
                while(res){
                    ans+=res%10;
                    res/=10;
                }
                res=ans;
            }
            num/=10;
        }
        
        return res;
    }
};