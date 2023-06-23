class Solution {
    // int res=2;
    // void dfs(vector<int> nums,int i,int seq,int cnt){
    //     res=max(res,cnt);
    //     for(int j=i+1;j<nums.size();j++){
    //         if(nums[j]-nums[i]==seq){
    //             // cout<<seq<<" "<<j<<" "<<i<<" "<<" "<<cnt<<endl;
    //             dfs(nums,j,seq,cnt+1);
    //         }
    //     }
    // }
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n=nums.size(),res=2;
        unordered_map<int,int> mp[n+1];
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int diff=nums[i]-nums[j];
                int cnt=1;
                if(mp[j].count(diff)){
                    cnt=mp[j][diff];
                }
                mp[i][diff]=1+cnt;
                res=max(res,mp[i][diff]);
            }
        }
        return res;
    }
};