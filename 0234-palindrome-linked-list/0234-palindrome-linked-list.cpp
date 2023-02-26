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
        ListNode* Reverse(ListNode* cur){
            ListNode *prev=NULL,*nextNode=cur;
            while(cur){
                nextNode=cur->next;
                cur->next=prev;
                prev=cur;
                cur=nextNode;
            }
            return prev;
        }
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head,*fast=head;
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *revList;
        if(!fast){
            revList=Reverse(slow);
        }
        else{
            revList=Reverse(slow->next);
        }
        while(revList){
            if(head->val!=revList->val){
                return false;
            }
            // cout<<revList->val<<" "<<head->val<<endl;
            head=head->next;
            revList=revList->next;
        }
        return true;
    }
};