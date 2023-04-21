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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        queue<pair<TreeNode*,int>> q;
        if(!root){
            return {};
        }
        int prevLevel=0,prevNum;
        q.push({root,0});
        while(!q.empty()){
            TreeNode* node=q.front().first;
            int level=q.front().second;
            q.pop();
            if(level>prevLevel){
                res.push_back(prevNum);
                prevLevel=level;
            }
            // cout<<node->val<<endl;
            prevNum=node->val;
            if(node->left){
                q.push({node->left,level+1});
            }
            if(node->right){
                q.push({node->right,level+1});
            }
        }
        res.push_back(prevNum);
        return res;
    }
};