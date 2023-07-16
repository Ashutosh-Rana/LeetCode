class Solution {
    int n,targt;
    map<pair<int,int>,int> dp;
    int dfs(int i,int &sum,vector<int> &nums){
        // cout<<"hi"<<endl;
        auto it=dp.find({i,sum});
        if(it!=dp.end()){
            return dp[{i,sum}];
        }
        if(i==n && sum==targt){
            // res++;
            return 1;
        }
        if(i>=n){
            return 0;
        }
        sum=sum+nums[i];
        // i++;
        int pos=dfs(i+1,sum,nums);
        // i--;
        sum=sum-2*nums[i];
        // i++;
        int neg=dfs(i+1,sum,nums);
        // i--;
        sum+=nums[i];
        // cout<<i<<" "<<pos+neg<<endl;
        dp[{i,sum}]=pos+neg;
        return dp[{i,sum}];
        
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // int res=0,sum=0,i=nums.size()-1;
        // map<pair<int,int>,int> dp;
        int sum=0;
        n=nums.size(),targt=target;
        int res=dfs(0,sum,nums);
        return res;
    }
};