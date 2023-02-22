class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size(),max_ele=0,sum=0;
        for(int a:weights){
            max_ele=max(a,max_ele);
            sum+=a;
        }
        int l=max_ele,r=sum,mid;
        int res,temp_sum=0,cnt=0;
        while(l<=r){
            mid=l+(r-l)/2;
            temp_sum=0;
            cnt=0;
            for(int i=0;i<n;i++){
                temp_sum+=weights[i];
                if(temp_sum>=mid){
                    cnt++;
                    temp_sum==mid? temp_sum=0 : temp_sum=weights[i]  ;
                }
            }
            //cout<<l<<" "<<r<<" "<<" "<<cnt<<endl;
            if(temp_sum){
                cnt++; 
            }
            if(cnt>days){
                l=mid+1;
            }
            else{
                r=mid-1;
                res=mid;
            }
        }
        return res;
    }
};