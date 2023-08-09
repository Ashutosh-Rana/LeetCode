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
    void dfs(TreeNode* root){
        if(root){
            res=max(res,maxLen(root->left)+maxLen(root->right));
        }
        else{
            return;
        }
        dfs(root->left);
        dfs(root->right);
    }
    int maxLen(TreeNode* root){
        // res=max(res,cnt);
        if(!root){
            return 0;
        }
        int l=maxLen(root->left);
        int r=maxLen(root->right);
        return max(l+1,r+1);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;
    }
};