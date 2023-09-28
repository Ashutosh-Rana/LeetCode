class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> res;
        for(int a:nums){
            if(a%2==0){
                res.push_back(a);
            }
        }
        for(int a:nums){
            if(a%2){
                res.push_back(a);
            }
        }
        return res;
    }
};