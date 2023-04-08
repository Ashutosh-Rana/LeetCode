/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
private:
    void dfs(Node* node,Node* copy,unordered_map<int,Node*> &visited){
        visited[copy->val]=copy;
        for(Node* n:node->neighbors){
            if(visited[n->val]==NULL){
                // cout<<n->val;
                Node* newNode=new Node(n->val);
                copy->neighbors.push_back(newNode);
                dfs(n,newNode,visited);
            }
            else{
                // cout<<n->val;
                copy->neighbors.push_back(visited[n->val]);
            }
        }
    }
public:
    Node* cloneGraph(Node* node) {
        if(node==NULL ){
            return node;
        }
        Node* copy=new Node(node->val);
        unordered_map<int,Node*> visited;
        dfs(node,copy,visited);
        return copy;
    }
};