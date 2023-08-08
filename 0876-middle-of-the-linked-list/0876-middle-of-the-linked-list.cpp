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
    ListNode* middleNode(ListNode* head) {
        int cnt=0;
        ListNode* cur=head;
        while(cur){
            cur=cur->next;
            cnt++;
        }
        int cnt2=0;
        while(head){
            cnt2++;
            if(cnt2-1==cnt/2){
                return head;
            }
            head=head->next;
        }
        return head;
    }
};