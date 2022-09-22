class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int sum,cnt,n=nums.size(),q=queries.size();
        vector<int> res;
        sort(nums.begin(),nums.end());
        for(int a:queries){
            sum=0,cnt=0;
            for(int b:nums){
                sum+=b;
                if(sum<=a){
                    cnt++;
                }
            }
            res.push_back(cnt);
        }
        return res;
    }
};