class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int,int> left,end;
        for(int a:nums){
            left[a]++;
        }
        for(int a:nums){
            if(left[a]==0){
                continue;
            }
            left[a]--;
            if(end[a-1]>0){
                end[a-1]--;
                end[a]++;
            }
            else if(left[a+1]>0 && left[a+2]>0){
                left[a+1]--;
                left[a+2]--;
                end[a+2]++;
            }
            else{
                return false;
            }
        }
        return true;
    }
};