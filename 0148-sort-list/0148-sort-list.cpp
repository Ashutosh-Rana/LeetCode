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
    ListNode* mergeList(ListNode* l1,ListNode* l2){
        ListNode* cur=new ListNode(0);
        ListNode* res=cur;
        while(l1 && l2){
            if(l1->val<=l2->val){
                cur->next=l1;
                l1=l1->next;
            }
            else{
                cur->next=l2;
                l2=l2->next;
            }
            cur=cur->next;
        }
        if(l1){
            cur->next=l1;
        }
        if(l2){
            cur->next=l2;
        }
        ListNode* result=res->next;
        // delete(cur);
        delete(res);
        return result;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode *slow=head,*fast=head,*temp;
        while(fast && fast->next){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        temp->next=NULL;
        ListNode* left=sortList(head);
        ListNode* right=sortList(slow);
        return mergeList(left,right);
        
        // vector<int> v;
        // ListNode* cur=head;
        // while(cur){
        //     v.push_back(cur->val);
        //     cur=cur->next;
        // }
        // sort(v.begin(),v.end());
        // ListNode* newHead = new ListNode(v[0]);
        // ListNode* res=newHead;
        // for(int i=1;i<v.size();i++){
        //     ListNode* temp=new ListNode(v[i]);
        //     newHead->next=temp;
        //     newHead=newHead->next;
        // }
        // return res;
    }
};