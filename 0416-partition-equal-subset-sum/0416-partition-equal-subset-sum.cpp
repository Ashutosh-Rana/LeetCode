class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size(),sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum%2!=0){
            return false;
        }
        int target=sum/2;
        unordered_set<int> dp={0},nextDP;
        for(int i=0;i<n;i++){
            for(auto it=dp.begin();it!=dp.end();it++){
                if(*it+nums[i]==target){
                    return true;
                }
                nextDP.insert(*it+nums[i]);
                nextDP.insert(*it);
            }
            dp=nextDP;
        }
        return false;
    }
};