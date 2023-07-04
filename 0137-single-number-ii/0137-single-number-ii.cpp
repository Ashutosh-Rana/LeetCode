class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size(),res=0;
        long shift=1;
        for(int i=0;i<32;i++){
            long cnt=0;
            for(int j=0;j<n;j++){
                cnt+=(nums[j]&(1<<i));
            }
            if(cnt%3){
                res+=shift;
            }
            shift*=2;
        }
        return res;
    }
};