class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        // int n=nums.size(),cnt=0,sum=0,i=0;
        // sort(nums.begin(),nums.end());
        // int max=nums[n-1];
        // while(i<n && sum!=max){
        //     if(nums[i]==0 || (i>0 && nums[i]==nums[i-1])){
        //         i++;
        //         continue;
        //     }
        //     if(i!=0){
        //         sum+=nums[i]-nums[i-1];
        //     }
        //     else{
        //         sum+=nums[i];
        //     }
        //     cnt++;
        //     i++;
        // }
        // return cnt;
        unordered_set<int> s(nums.begin(),nums.end());
        int cnt=0;
        for(int a:s){
            if(a){
                cnt++;
            }
        }
        return cnt;
    }
};