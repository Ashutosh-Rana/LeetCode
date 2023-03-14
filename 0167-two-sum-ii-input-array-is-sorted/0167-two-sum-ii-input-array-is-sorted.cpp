class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0,r=numbers.size()-1;
        // vector<int> res;
        while(l<r){
            if(numbers[l]+numbers[r]==target){
                // res.push_back({l+1,r+1});
                return {l+1,r+1};
            }
            else if(numbers[l]+numbers[r]<target){
                l++;
            }
            else{
                r--;
            }
        }
        return {l+1,r+1};
    }
};