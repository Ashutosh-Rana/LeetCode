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
    ListNode* reverseList(ListNode* head){
        ListNode* cur=head,*prev=NULL;
        while(cur){
            ListNode* nextNode=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nextNode;
        }
        return prev;
    }
public:
    int pairSum(ListNode* head) {
        ListNode* slow=head,*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* head2=reverseList(slow);
        int res=0;
        while(head2){
            res=max(res,head2->val+head->val);
            head=head->next;
            head2=head2->next;
        }
        return res;
    }
};