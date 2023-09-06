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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        ListNode* cur=head;
        int cnt=0;
        while(cur){
            cnt++;
            cur=cur->next;
        }
        cur=head;
        while(k){
            int n=ceil(float(cnt)/k);
            ans.push_back(cur);
            // cout<<n<<" "<<cur->val<<endl;
            for(int i=0;i<n-1;i++){
                cur=cur->next;
                cnt--;
            }
            if(cur){
                ListNode* prev=cur;
                cur=cur->next;
                prev->next=NULL;
                cnt--;
            }
            k--;
        }
        return ans;
    }
};