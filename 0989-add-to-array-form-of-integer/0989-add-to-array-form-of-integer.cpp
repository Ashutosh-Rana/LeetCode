class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int a=0,n=num.size(),carry=0;
        vector<int> res,k_arr;
        reverse(num.begin(),num.end());
        
        while(k){
            k_arr.push_back(k%10);
            k/=10;
        }
        int max_len=max(num.size(),k_arr.size());
        int digitA,digitB,total;
        for(int i=0;i<max_len;i++){
            if(i<n){
                digitA=num[i];
            }
            else{
                digitA=0;
            }
            if(i<k_arr.size()){
                digitB=k_arr[i];
            }
            else{
                digitB=0;
            }
            total=digitA+digitB+carry;
            res.push_back(total%10);
            carry=total/10;
        }
        if(carry){
            res.push_back(carry);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};