class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<int> prefix(n+1,0),postfix(n+1,0);
        postfix[n]=0,prefix[0]=0;
        for(int i=n-1;i>=0;i--){
            if(customers[i]=='Y'){
                postfix[i]=postfix[i+1]+1;
            }
            else{
                postfix[i]=postfix[i+1];
            }
        }
        for(int i=0;i<n;i++){
            if(customers[i]=='N'){
                prefix[i+1]=prefix[i]+1;
            }
            else{
                prefix[i+1]=prefix[i];
            }
        }
        int res=n,minm=n;
        for(int i=0;i<=n;i++){
            // cout<<i<<" "<<prefix[i]<<" "<<postfix[i]<<endl;
            if(prefix[i]+postfix[i]<minm){
                minm=prefix[i]+postfix[i];
                res=i;
            }
        }
        return res;
    }
};