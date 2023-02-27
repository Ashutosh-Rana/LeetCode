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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head,*temp2=head;
        int cnt=0,cnt2=0;
        while(temp){
            cnt++;
            temp=temp->next;
        }
        cnt2=cnt-n;
        if(cnt2==0){
            return head->next;
        }
        for(int i=0;i<cnt2-1;i++){
            temp2=temp2->next;
        }
        temp2->next=temp2->next->next;
        // while(head){
        //     cout<<head->val<<" ";
        //     head=head->next;
        // }
        // cout<<endl<<cnt;
        return head;
    }
};