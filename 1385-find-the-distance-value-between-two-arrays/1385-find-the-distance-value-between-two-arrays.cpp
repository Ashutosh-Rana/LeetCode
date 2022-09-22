class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int res=0,flag;
        for(int a1:arr1){
            flag=1;
            for(int a2:arr2){
                if(abs(a1-a2)>d){
                    continue;
                }
                else{
                    flag=0;
                    break;
                }
            }
            if(flag){
                res++;
            }
        }
        return res;
    }
};