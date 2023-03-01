/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    // private:
    // ListNode* Reverse(ListNode* head){
    //     ListNode *nextNode,*prev=NULL;
    //     while(head){
    //         nextNode=head->next;
    //         head->next=prev;
    //         prev=head;
    //         head=nextNode;
    //     }
    //     return prev;
    // }
public:
    void deleteNode(ListNode* node) {
        ListNode* nextNode=node->next;
        *node=*nextNode;
        delete nextNode;
    }
};