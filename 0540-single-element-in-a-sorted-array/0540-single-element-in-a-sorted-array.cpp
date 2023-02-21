class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0,r=nums.size()-1,mid,n=nums.size();
        while(l<=r){
            mid=(l+r)/2;
            cout<<l<<" "<<mid<<" "<<r<<endl;
            if(mid<n-1 && nums[mid]==nums[mid+1]){
                int sz=(n-1)-(mid+1);
                if(sz%2==0){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else if(mid>0 && nums[mid]==nums[mid-1]){
                int sz=mid-1-0;
                if(sz%2==0){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
            else{
                return nums[mid];
            }
        }
        return -1;
    }
};