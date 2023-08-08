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
    int res=0;
    void dfs(TreeNode* root,int cnt){
        res=max(res,cnt);
        if(!root){
            return;
        }
        dfs(root->left,cnt+1);
        dfs(root->right,cnt+1);
    }
public:
    int maxDepth(TreeNode* root) {
        dfs(root,0);
        return res;
    }
};