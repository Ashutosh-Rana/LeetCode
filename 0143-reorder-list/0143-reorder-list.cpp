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
        // ListNode* res=new ListNode(0);
        // ListNode* start=res;
        
        ListNode *slow=head,*fast=head,*res=head;
        // res->next=head;
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* revList;
        // cout<<slow->val;
        revList=Reverse(slow->next);
        slow->next=NULL;
        // cout<<slow->next->val<<endl;
        // cout<<revList->next->val;
        while(revList ){
            // cout<<temp->val<<" "<<revList->val<<endl;
            cout<<res->val<<" "<<revList->val<<endl;
            ListNode* temp2=revList;
            revList=revList->next;
            // cout<<res->next->val<<endl;
            ListNode *nextNode=res->next;
            res->next=temp2;
            temp2->next=nextNode;
            res=res->next->next;
            // cout<<res->val<<endl;
            // res->next=revList;
            // res=res->next;
            // temp=temp->next;
            // revList=revList->next;
            // cout<<temp->val<<endl;
        }
        // if(fast){
        //     res->next=;
        // }
    }
};