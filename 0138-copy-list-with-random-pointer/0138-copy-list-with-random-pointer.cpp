/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;
        if(!head) return NULL;
        Node* cur=head;
        while(cur){
            mp[cur]=new Node(cur->val);
            cur=cur->next;
        }
        int cur_val=head->val;
        Node *cur2=head;
        mp[cur2]=new Node(cur_val);
        Node *res=mp[cur2];
        while(cur2){
            // cout<<res->val<<endl;
            mp[cur2]->next=mp[cur2->next];
            mp[cur2]->random=mp[cur2->random];
            cur2=cur2->next;
            // res=res->next;
        }
        return res;
    }
};