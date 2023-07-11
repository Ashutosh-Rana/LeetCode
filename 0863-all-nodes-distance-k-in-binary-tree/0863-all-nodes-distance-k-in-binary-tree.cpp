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
    void markParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent){
        if(!root){
            return;
        }
        if(root->left){
            parent[root->left]=root;
        }
        if(root->right){
            parent[root->right]=root;
        }
        markParent(root->left,parent);
        markParent(root->right,parent);
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent;
        markParent(root,parent);
        int cur_level=0;
        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> vis;
        q.push(target);
        vis[target]=true;
        while(!q.empty()){
            if(cur_level==k){
                break;
            }
            cur_level++;
            int s=q.size();
            for(int i=0;i<s;i++){
                TreeNode* cur=q.front();
                q.pop();
                // cout<<cur->val<<" ";
                if(cur->left && !vis[cur->left]){
                    // cout<<cur->left->val<<" ";
                    q.push(cur->left);
                    vis[cur->left]=true;
                }
                if(cur->right && !vis[cur->right]){
                    // cout<<cur->right->val<<" ";
                    q.push(cur->right);
                    vis[cur->right]=true;
                }
                if(parent[cur] && !vis[parent[cur]]){
                    // cout<<parent[cur]->val;
                    q.push(parent[cur]);
                    vis[parent[cur]]=true;
                }
                // cout<<endl;
            }
        }
        vector<int> res;
        while(!q.empty()){
            int cur=q.front()->val;
            q.pop();
            res.push_back(cur);
        }
        return res;
    }
};