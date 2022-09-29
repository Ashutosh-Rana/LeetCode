class Solution {
private:
    int quickSelect(int k,int l,int r,vector<int> nums){
        int p=l,pivot=nums[r];
        for(int i=l;i<r;i++){
            if(nums[i]<pivot){
                swap(nums[i],nums[p]);
                p++;
            }
        }
        swap(nums[p],nums[r]);
        if(k>p){
            return quickSelect(k,p+1,r,nums);
        }
        else if(k<p){
            return quickSelect(k,l,p-1,nums);
        }
        else{
            return nums[p];
        }
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int,vector<int>,greater<int>> pq;
        // for(int a:nums){
        //     pq.push(a);
        //     if(pq.size()>k){
        //         pq.pop();
        //     }
        // }
        // return pq.top();
        k=nums.size()-k;
        int res=quickSelect(k,0,nums.size()-1,nums);
        return res;
    }
};