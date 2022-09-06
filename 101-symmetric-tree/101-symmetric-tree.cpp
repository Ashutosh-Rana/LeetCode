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
public:
    vector<int> v;
    vector<int> preorderTraversal(TreeNode* root){
        if(root==NULL){
            v.push_back(-1);
            return v;
        }
        v.push_back(root->val);
        preorderTraversal(root->left);
        // v.push_back(root->val);
        preorderTraversal(root->right);
        return v;
    }
    
    vector<int> Traversal2(TreeNode* root){
        if(root==NULL){
            v.push_back(-1);
            return v;
        }
        v.push_back(root->val);
        Traversal2(root->right);
        // v.push_back(root->val);
        Traversal2(root->left);
        return v;
    }
    
    bool isSymmetric(TreeNode* root) {
        vector<int> a,b;
        a=preorderTraversal(root->left);
        v={};
        b=Traversal2(root->right);
        if(a==b){
            return true;
        }
        return false;
    }
};