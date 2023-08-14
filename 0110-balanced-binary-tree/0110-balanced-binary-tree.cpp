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
    int flag=0,res=1;
    int dfs(TreeNode* root){
        if(flag) return res;
        if(!root){
            return -1;
        }
        int leftH=1+dfs(root->left);
        int rightH=1+dfs(root->right);
        if(abs(leftH-rightH)>1){
            flag=1;
            res=0;
        }
        return max(leftH,rightH);
    }
public:
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return res;
    }
};