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
    int dfs(TreeNode* root,int &flag){
        if(!root){
            return -1;
        }
        if(flag){
            return 0;
        }
        int leftMax=1+dfs(root->left,flag);
        int rightMax=1+dfs(root->right,flag);
        if(abs(leftMax-rightMax)>1){
            flag=1;
            return 0;
        }
        return max(leftMax,rightMax);
    }
public:
    bool isBalanced(TreeNode* root) {
        int flag=0;
        dfs(root,flag);
        return flag? false:true;
    }
};