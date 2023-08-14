class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int a:nums){
            pq.push(a);
        }
        int cnt=0;
        while(!pq.empty()){
            int ele=pq.top();
            pq.pop();
            cnt++;
            if(cnt==k){
                return ele;
            }
        }
        return 0;
    }
};