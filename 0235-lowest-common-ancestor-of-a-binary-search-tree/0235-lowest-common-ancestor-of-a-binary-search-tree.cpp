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
private:
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q,int &res){
        if(!root){
            return false;
        }
        if( (p->val<root->val && q->val>root->val) or (p->val>root->val && q->val<root->val) 
           or p->val==root->val or q->val==root->val ){
            res=root->val;
            return true;
        }
        else if((p->val<root->val && q->val<root->val)){
            if(dfs(root->left,p,q,res)){
                // res=root->val;
                return true;
            }
        }
        else if( p->val>root->val && q->val>root->val ){
            if(dfs(root->right,p,q,res)){
                return true;
            }
        }
        return false;
    }    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int res=0;
        dfs(root,p,q,res);
        TreeNode* ans=new TreeNode(res);
        return ans;
    }
};