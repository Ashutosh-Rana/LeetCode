class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n=nums.size(),cnt=0,res=cnt,l=0,h=n-1;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            cnt=n-i;
            if(nums[i]>=cnt && (i==0 || (i>0 && nums[i-1]<cnt))){
                return cnt;
            }
        }
        return -1;
        // while(l<=h){
        //     int mid=l+(h-l)/2;
        //     cnt=n-mid;
        //     if(nums[mid]>=cnt && (mid==0 || (mid>0 && nums[mid-1]<cnt)) ){
        //         res=cnt;
        //         h=mid-1;
        //     }
        //     else{
        //         l=mid+1;
        //     }
        // }
        // if(res==0){
        //     return -1;
        // }
        // return res;
    }
};