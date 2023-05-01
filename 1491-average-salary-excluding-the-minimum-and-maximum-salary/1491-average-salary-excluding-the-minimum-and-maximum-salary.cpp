class Solution {
public:
    double average(vector<int>& salary) {
        int minm=*min_element(salary.begin(),salary.end());
        int maxm=*max_element(salary.begin(),salary.end());
        int n=salary.size();
        double ans=0.00000;
        for(int i=0;i<n;i++){
            if(salary[i]==minm or salary[i]==maxm){
                continue;
            }
            else{
                ans+=salary[i];
            }
        }
        return ans/(n-2);
    }
};