class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int a:stones){
            pq.push(a);
        }
        while(pq.size()>1){
            int i=pq.top();
            pq.pop();
            int j=pq.top();
            pq.pop();
            if(i!=j){
                pq.push(i-j);
            }
        }
        if(pq.size()){
            return pq.top();
        }
        return 0;
    }
};