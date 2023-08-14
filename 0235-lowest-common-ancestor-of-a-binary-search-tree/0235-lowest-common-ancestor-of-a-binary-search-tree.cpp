/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
    TreeNode* dfs(TreeNode* root,TreeNode* p, TreeNode* q){
        // cout<<root->val<<endl;
        if(
            (p->val<root->val && q->val>root->val) or
           (p->val>root->val && q->val<root->val) or
            (p->val==root->val or q->val==root->val)
          )
        {
            return root;    
        }
        if(p->val<root->val && q->val<root->val){
            return dfs(root->left,p,q);
        }
        if(p->val>root->val && q->val>root->val){
            return dfs(root->right,p,q);
        }
        return root;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root,p,q);
    }
};