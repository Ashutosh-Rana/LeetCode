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
        ListNode* newHead;
        // vector<int> v;
public:
    
    Solution(ListNode* head) {
        newHead=head;
        // while(head){
        //     v.push_back(head->val);
        //     head=head->next;
        // }
    }
    
    int getRandom() {
        // int rand_val=rand()%(v.size());
        // return v[rand_val];
        ListNode* cur=newHead;
        int i=1,ans;
        while(cur){
            if(rand()%i==0){
                ans=cur->val;
            }
            i++;
            cur=cur->next;
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */