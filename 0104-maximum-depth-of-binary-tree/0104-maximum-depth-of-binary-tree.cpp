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
    int dfs(TreeNode* root,int cnt){
        if(!root){
            return cnt;
        }
        int maxLeft=dfs(root->left,cnt+1);
        int maxRight=dfs(root->right,cnt+1);
        return max(maxLeft,maxRight);
    }
public:
    int maxDepth(TreeNode* root) {
        int res=dfs(root,0);
        return res;
    }
};