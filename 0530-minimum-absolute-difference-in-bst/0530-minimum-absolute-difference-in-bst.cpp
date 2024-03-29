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
    TreeNode *prev=NULL;
private:
    void dfs(TreeNode* root){
       if(!root){
           return;
       }
        dfs(root->left);
        if(prev){
            res=min(res,root->val-prev->val);
        }
        prev=root;
        dfs(root->right);
    }
    // void dfs(TreeNode* root,vector<int>& v){
    //    if(!root){
    //        return;
    //    }
    //     dfs(root->left,v);
    //     v.push_back(root->val);
    //     dfs(root->right,v);
    // }
public:
    int getMinimumDifference(TreeNode* root) {
        // vector<int> v;
        dfs(root);
        // int res=INT_MAX;
        // for(int i=1;i<v.size();i++){
        //     res=min(res,v[i]-v[i-1]);
        // }
        return res;
    }
};