/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    vector<TreeNode*> backtrack(int n,vector<vector<TreeNode*>> &dp){
        if(!dp[n].empty()){
            return dp[n];
        }
        vector<TreeNode*> vec;
        if(n==1){
            return {new TreeNode()};
        }
        if(n%2==0){
            return vec;
        }
        for(int i=2;i<=n;i+=2){
            vector<TreeNode*> left=backtrack(i-1,dp);
            vector<TreeNode*> right=backtrack(n-i,dp);
            for(auto leftNode:left){
                for(auto rightNode:right){
                    vec.push_back(new TreeNode(0,leftNode,rightNode));
                }
            }
        }
        return dp[n]=vec;
    }
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<vector<TreeNode*>> dp(n+1);
        return backtrack(n,dp);
    }
};