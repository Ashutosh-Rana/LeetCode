class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n=dist.size(),maxm=*max_element(dist.begin(),dist.end());
        double hr=ceil(hour);
        if(n>hr){
            return -1;
        }
        int l=1,r=maxm*100,mid;
        while(l<r){
            mid=l+(r-l)/2;
            // cout<<l<<" "<<r<<" "<<mid<<endl;
            double t=0;
            for(int i=0;i<n-1;i++){
                t+=ceil(dist[i]/double(mid));
            }
            t+=dist[n-1]/double(mid);
            if(t>hour){
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        return r;
    }
};