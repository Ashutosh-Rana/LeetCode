class Solution {
public:
    int fillCups(vector<int>& amount) {
        int max_ele=0,sum=0;
        for(int a:amount){
            sum+=a;
            max_ele=max(max_ele,a);
        }
        return max(max_ele,(sum+1)/2);
    }
};