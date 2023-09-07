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
    ListNode* reverseList(ListNode* cur,int cnt){
        ListNode* nextNode,*prev=NULL;
        while(cnt){
            nextNode=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nextNode;
            cnt--;
        }
        // cout<<prev->val<<endl;
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *tmp=new ListNode();
        tmp->next=head;
        ListNode* first=tmp,*second=head;
        int cnt=right-left+1;
        if(cnt==1) return head;
        for(int i=1;i<left;i++){
            first=first->next;
        }
        for(int i=1;i<=right;i++){
            second=second->next;
        }
        ListNode *cur=first->next;
        // first->next=NULL;
        ListNode *prev=reverseList(cur,cnt);
        first->next=prev;
        while(cnt-1){
            prev=prev->next;
            // cout<<prev->val<<endl;
            cnt--;
        }
        // cout<<second->val<<endl;
        prev->next=second;
        return tmp->next;
    }
};