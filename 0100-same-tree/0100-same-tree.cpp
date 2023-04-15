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
    void dfs(TreeNode* p, TreeNode* q,int &flag){
        if(!p or !q){
            if(!p && !q){
                return;
            }
            else{
                flag=1;
                return;
            }
        }
        if(flag){
            return;
        }
        if(p->val==q->val){
            dfs(p->left,q->left,flag);
            dfs(p->right,q->right,flag);
        }
        else{
            flag=1;
            return;
        }
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        int flag=0;
        dfs(p,q,flag);
        return flag? false:true;
    }
};