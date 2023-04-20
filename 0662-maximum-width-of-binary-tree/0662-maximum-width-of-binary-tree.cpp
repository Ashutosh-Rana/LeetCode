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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,pair<unsigned long long,unsigned long long>>> q;
        q.push({root,{1,0}});//node,num,level
        unsigned long long prevLevel=0,prevNum=1,res=0;
        while(!q.empty()){
            TreeNode* node=q.front().first;
            unsigned long long num=q.front().second.first;
            unsigned long long level=q.front().second.second;
            q.pop();
            
            if(level>prevLevel){
                prevLevel=level;
                prevNum=num;
            }
            res=max(res,num-prevNum+1);
            if(node->left){
                q.push({node->left,{2*num,level+1}});
            }
            if(node->right){
                q.push({node->right,{2*num+1,level+1}});
            }
        }
        return res;
    }
};