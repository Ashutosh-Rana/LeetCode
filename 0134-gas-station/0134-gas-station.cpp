class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gas_sum=accumulate(gas.begin(),gas.end(),0);
        int cost_sum=accumulate(cost.begin(),cost.end(),0);
        if(gas_sum<cost_sum){
            return -1;
        }
        int tank=0,start=0,total_neg=0,n=gas.size();
        for(int i=0;i<n;i++){
            tank+=gas[i]-cost[i];
            if(tank<0){
                total_neg+=tank;
                start=i+1;
                tank=0;

            }
        }
        if(total_neg+tank<0){
            return -1;
        }
        return start;
    }
};