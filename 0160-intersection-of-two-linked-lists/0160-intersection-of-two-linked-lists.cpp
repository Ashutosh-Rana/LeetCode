/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // ListNode * temp1=headA,*temp2;
        // while(temp1){
        //     temp2=headB;
        //     while(temp2){
        //         if(temp1==temp2){
        //             return temp1;
        //         }
        //         temp2=temp2->next;
        //     }
        //     temp1=temp1->next;
        // }
        // return NULL;
        ListNode *p1=headA,*p2=headB;
        while(p1 && p2 && p1!=p2){
            p1=p1->next;
            p2=p2->next;
            if(p1==p2){
                return p1;
            }
            if(p1==NULL){
                p1=headB;
            }
            if(p2==NULL){
                p2=headA;
            }
        }
        return p1;
    }
};