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
    ListNode* Reverse(ListNode *head){
        if(!head || !head->next){
            return head;
        }
        ListNode* newHead=Reverse(head->next);
        ListNode* headNext=head->next;
        headNext->next=head;
        head->next=NULL;
        return newHead;
    }
public:
    ListNode* reverseList(ListNode* head) {
        // if(head==NULL){
        //     return head;
        // }
        // ListNode *prev=NULL,*cur=head,*nextNode;
        // while(cur!=NULL){
        //     nextNode=cur->next;
        //     cur->next=prev;
        //     prev=cur;
        //     cur=nextNode;
        // }
        return Reverse(head);
        //return prev ;
        //return prev;
    }
};