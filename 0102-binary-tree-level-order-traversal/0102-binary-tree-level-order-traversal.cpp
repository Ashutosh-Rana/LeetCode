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
    void dfs(TreeNode* root,vector<vector<int>> &res,int i){
        if(!root){
            return;
        }
        // cout<<root->val<<" "<<i<<" "<<endl;
        res[i].push_back(root->val);
        dfs(root->left,res,i+1);
        dfs(root->right,res,i+1);
    }
    
    int maxH(TreeNode* root){
        if(!root){
            return -1;
        }
        int leftMax=1+maxH(root->left);
        int rightMax=1+maxH(root->right);
        return max(leftMax,rightMax);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root){
            return {};
        }
        int maxHeight=maxH(root);
        vector<vector<int>> res(maxHeight+1);
        dfs(root,res,0);
        return res;
    }
};