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
private:
    int res=0;
    void dfs(TreeNode* root,int maxm){
        if(!root){
            return;
        }
        maxm=max(root->val,maxm);
        if(root->val>=maxm){
            res++;
        }
        dfs(root->left,maxm);
        dfs(root->right,maxm);
    }
public:
    int goodNodes(TreeNode* root) {
        dfs(root,root->val);
        return res;
    }
};