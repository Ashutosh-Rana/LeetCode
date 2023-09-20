class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size(),sum=0,res=0;
        for(int a:nums) sum+=a;
        int target=sum-x,start_idx=0;
        sum=0;
        bool found=false;
        for(int end_idx=0;end_idx<n;end_idx++){
            sum+=nums[end_idx];
            while(sum>target && start_idx<=end_idx){
                sum-=nums[start_idx];
                start_idx++;
            }
            // cout<<start_idx<<" "<<end_idx<<" "<<sum<<endl;            
            if(sum==target){
                found=true;
                res=max(res,end_idx-start_idx+1);
                // cout<<start_idx<<" "<<end_idx<<endl;
            }
        }
        return found? n-res : -1;
    }
};