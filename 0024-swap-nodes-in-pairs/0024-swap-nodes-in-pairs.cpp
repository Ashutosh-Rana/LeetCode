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
    ListNode* swapPairs(ListNode* head) {
        ListNode* h=head,*cur=head,*prev=new ListNode(2),*res=prev;
        while(cur && cur->next){
            ListNode *temp=cur, *nextNode=cur->next,*nxt_nxt=cur->next->next;
            temp->next=NULL,nextNode->next=NULL;
            prev->next=nextNode;
            prev=prev->next;
            // cur=nextNode;
            prev->next=temp;
            prev=prev->next;
            // cur=cur->next;
            // prev=cur;
            cur=nxt_nxt;
            // cur=nxt_nxt;
        }
        prev->next=cur;
        return res->next;
    }
};