class KthLargest {
private:
    priority_queue<int,vector<int>,greater<int>> pq;
    int Size;
public:
    KthLargest(int k, vector<int>& nums) {
        Size=k;
        for(int a:nums){
            pq.push(a);
            if(pq.size()>k){
                pq.pop();
            }
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>Size){
                pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */