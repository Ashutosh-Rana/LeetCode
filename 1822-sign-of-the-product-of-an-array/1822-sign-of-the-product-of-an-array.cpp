// #define ll long long
class Solution {
public:
    int arraySign(vector<int>& nums) {
        int cnt=0;
        for(int a:nums){
            if(a==0){
                return 0;
            }
            else if(a<0){
                cnt++;
            }
        }
        if(cnt%2){
            return -1;
        }
        return 1;
    }
};