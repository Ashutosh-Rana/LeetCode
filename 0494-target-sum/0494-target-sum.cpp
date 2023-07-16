// class Solution {
//     int dfs(int i,int &sum,int target,vector<int> nums,
//             map<pair<int,int>,int> &dp){
//         // cout<<"hi"<<endl;
//         if(i==nums.size() && sum==target){
//             // res++;
//             return 1;
//         }
//         if(i>=nums.size()){
//             return 0;
//         }
//         if(dp[{i,sum}]){
//             return dp[{i,sum}];
//         }
//         sum=sum+nums[i];
//         // i++;
//         int pos=dfs(i+1,sum,target,nums,dp);
//         // i--;
//         sum=sum-2*nums[i];
//         // i++;
//         int neg=dfs(i+1,sum,target,nums,dp);
//         // i--;
//         sum+=nums[i];
//         // cout<<i<<" "<<pos+neg<<endl;
//         dp[{i,sum}]=pos+neg;
//         return dp[{i,sum}];
        
//     }
// public:
//     int findTargetSumWays(vector<int>& nums, int target) {
//         int res=0,sum=0,i=0;
//         map<pair<int,int>,int> dp;
//         res=dfs(i,sum,target,nums,dp);
//         return res;
//     }
// };


class Solution {
public:
    
        
    /*
        1, 1, 1, 1, 1
        +  +  +  +  + 
        +  +  +  +  -
        +  +  +  -  -
        +  +  +  -  +
        +  +  -  -  -
        +  +  -  +  -
    */
    
    int n;
    int target;
    map<pair<int,int>,int> cache;
    int DFS(vector<int>& nums,int currSum, int i)
    {
        auto find = cache.find({i,currSum});
        
        if (find != cache.end())
            return find->second;
        
        if (i == n && currSum == target)
        {
            return 1;
        }
        if(i >= n)
            return 0;

        return cache[{i,currSum}] = DFS(nums,currSum + nums[i],i + 1) + DFS(nums,currSum - nums[i],i + 1);
    }
    
    int findTargetSumWays(vector<int>& nums, int S) 
    {
        n = nums.size();
        target = S;
        
        if(n == 0)
            return 0;
        
        return DFS(nums,0,0);
    }
};