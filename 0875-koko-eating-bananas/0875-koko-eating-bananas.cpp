class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // sort(piles.begin(),piles.end());
        
        int l=1,n=piles.size(),r=0;
        
        for(int i=0;i<n;i++){
            r=max(r,piles[i]);
        }
        
        if(n==1){
            return ceil(piles[0]/double(h));
        }
        while(l<=r){
            int mid=l+(r-l)/2;
            // cout<<l<<" "<<mid<<" "<<r<<endl;
            long sum=0;
            for(int i=0;i<n;i++){
                sum+=ceil(piles[i]/(double)mid);
                // cout<<floor(piles[i]/(float)mid)<<" ";
            }
            // cout<<endl;
            if(sum<=h){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return r+1;
    }
};