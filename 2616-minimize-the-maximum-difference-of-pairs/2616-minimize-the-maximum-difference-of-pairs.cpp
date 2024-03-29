class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),l=0,r=nums[n-1]-nums[0],mid;
        while(l<r){
            mid=l+(r-l)/2;
            int k=0;
            for(int i=1;i<n && k<p;i++){
                if(nums[i]-nums[i-1]<=mid){
                    k++;
                    i++;
                }
            }
            if(k>=p){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        return l;
    }
};