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
    int res=INT_MAX;
    void dfs(TreeNode* root,int cnt){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            res=min(res,cnt);
            return;
        }
        dfs(root->left,cnt+1);
        dfs(root->right,cnt+1);
    }
public:
    int minDepth(TreeNode* root) {
        if(!root){
            return 0;
        }
        dfs(root,1);
        return res;
    }
};