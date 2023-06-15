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
    int maxLevelSum(TreeNode* root) {
        int max_sum=INT_MIN,sum=0,prev=1,res=1;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int cur=q.front().second;
            q.pop();
            if(prev!=cur){
                if(sum>max_sum){
                    max_sum=sum;
                    res=prev;
                }
                sum=0;
            }
            sum+=node->val;
            if(node->left){
                q.push({node->left,cur+1});
            }
            if(node->right){
                q.push({node->right,cur+1});
            }
            prev=cur;
        }
        if(sum>max_sum){
            return prev;
        }
        return res;
    }
};