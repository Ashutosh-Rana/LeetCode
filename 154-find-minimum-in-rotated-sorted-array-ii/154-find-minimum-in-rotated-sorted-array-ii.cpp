class Solution {
private:
    bool checkEqual(int l,int r,vector<int>& nums){
        for(int i=l;i<r;i++){
            if(nums[l]!=nums[i+1]){
                return false;
            }
        }
        return true;
    }
public:
    int findMin(vector<int>& nums) {
        int res=nums[0],l=0,r=nums.size()-1,mid;
        while(l<=r){
            if(nums[l]<nums[r]){
                res=min(res,nums[l]);
                break;
            }
            mid=l+(r-l)/2;
            res=min(res,nums[mid]);
            if(checkEqual(mid,r,nums)){
                r=mid-1;
            }
            else if(nums[l]<=nums[mid]){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return res;
    }
};