class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        priority_queue<pair<int,int>> pq;
        int n=position.size();
        for(int i=0;i<position.size();i++){
            pq.push({position[i],speed[i]});
        }
        stack<pair<int,int>> st;
        st.push({pq.top().first,pq.top().second});
        // cout<<pq.top().first<<endl;
        pq.pop();
        while(!pq.empty()){
            // cout<<st.top().first<<endl;
            float t1=(target-st.top().first)/(float)st.top().second;
            float t2=(target-pq.top().first)/(float)pq.top().second;
            // cout<<t1<<" "<<t2<<endl;
            if(t2>t1){
                st.push({pq.top().first,pq.top().second});
            }
            pq.pop();
        }
        return st.size();
    }
};