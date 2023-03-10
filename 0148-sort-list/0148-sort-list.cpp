/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head){
            return NULL;
        }
        vector<int> v;
        ListNode* cur=head;
        while(cur){
            v.push_back(cur->val);
            cur=cur->next;
        }
        sort(v.begin(),v.end());
        ListNode* newHead = new ListNode(v[0]);
        ListNode* res=newHead;
        for(int i=1;i<v.size();i++){
            ListNode* temp=new ListNode(v[i]);
            newHead->next=temp;
            newHead=newHead->next;
        }
        return res;
    }
};