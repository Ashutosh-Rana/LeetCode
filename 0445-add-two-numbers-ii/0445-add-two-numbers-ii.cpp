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
    ListNode* reverse(ListNode* head){
        ListNode  *prev=NULL,*cur=head,*nextNode;
        while(cur){
            nextNode=cur->next;
            cur->next=prev;
            prev=cur;
            cur=nextNode;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l1_rev=reverse(l1);
        ListNode *l2_rev=reverse(l2);
        ListNode *res=new ListNode(0);
        // cout<<l1_rev->val<<" "<<l2_rev->val<<endl;
        ListNode *cur=res;
        int carry=0,sum=0;
        while(l1_rev or l2_rev){
            // int sum;
            if(l1_rev && l2_rev){
                // cout<<"Hi"<<endl;
                sum=l1_rev->val+l2_rev->val+carry;
                // cout<<sum<<endl;
                l1_rev=l1_rev->next;
                l2_rev=l2_rev->next;
            }
            else if(l1_rev){
                sum=l1_rev->val+carry;
                l1_rev=l1_rev->next;
            }
            else{
                sum=l2_rev->val+carry;
                l2_rev=l2_rev->next;
            }
            // cout<<sum<<endl;
            carry=sum/10;
            sum%=10;
            ListNode* tmp=new ListNode(sum);
            cur->next=tmp;
            cur=cur->next;
        }
        if(carry){
            ListNode* tmp=new ListNode(carry);
            cur->next=tmp;
        }
        ListNode *final_res=reverse(res->next);
        return final_res;
    }
};