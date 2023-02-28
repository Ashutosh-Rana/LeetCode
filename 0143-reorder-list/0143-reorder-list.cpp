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
    private:
        ListNode* Reverse(ListNode* newHead){
            ListNode* prev=NULL,*nextNode=newHead;
            while(newHead){
                nextNode=newHead->next;
                newHead->next=prev;
                prev=newHead;
                newHead=nextNode;
            }
            return prev;
        }
public:
    void reorderList(ListNode* head) {
        ListNode* temp=head;
        ListNode *slow=head,*fast=head,*res=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* revList;
        revList=Reverse(slow->next);
        slow->next=NULL;
        while(revList ){
            // cout<<res->val<<" "<<revList->val<<endl;
            ListNode* temp2=revList;
            revList=revList->next;
            ListNode *nextNode=res->next;
            res->next=temp2;
            temp2->next=nextNode;
            res=res->next->next;
        }
    }
};