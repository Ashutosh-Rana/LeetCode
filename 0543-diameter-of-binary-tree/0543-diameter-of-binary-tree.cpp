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
    int dfs(TreeNode* root,int &res){
        if(!root){
            return -1;
        }
        int leftMax=dfs(root->left,res);
        int rightMax=dfs(root->right,res);
        res=max(res,2+leftMax+rightMax);
        return 1+max(leftMax,rightMax);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root,res);
        return res;
    }
};