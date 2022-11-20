class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int small=INT_MAX,big=INT_MAX;
        for(int a:nums){
            if(a<=small){
                small=a;
            }
            else if(a<=big){
                big=a;
            }
            else{
                return true;
            }
        }
        return false;
    }
};