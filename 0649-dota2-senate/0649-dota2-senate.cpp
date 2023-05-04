class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> R_q,D_q;
        int n=senate.size();
        for(int i=0;i<n;i++){
            if(senate[i]=='R'){
                R_q.push(i);
            }
            else{
                D_q.push(i);
            }
        }
        while(!R_q.empty() && !D_q.empty()){
            int R_idx=R_q.front(),D_idx=D_q.front();
            R_q.pop(),D_q.pop();
            // cout<<R_idx<<" "<<D_idx;
            if(R_idx<D_idx){
                R_q.push(R_idx+n);
            }
            else{
                D_q.push(D_idx+n);
            }
        }
        if(D_q.empty()){
            return "Radiant";
        }
        return "Dire";
    }
};