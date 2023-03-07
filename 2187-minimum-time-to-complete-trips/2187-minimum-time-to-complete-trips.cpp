class Solution {
    private:
        long long countTrips(vector<int>& time, long long givenTime){
            long long cnt=0;
            for(long long a:time){
                cnt+=givenTime/a;
            }
            return cnt;
        }
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        // long long res=0;
        // long long i=0,trips=0;
        long long l=1,min_ele=*min_element(time.begin(),time.end());
        long long r=min_ele * totalTrips;
        while(l<r){
            long long mid=l+(r-l)/2;
            if(countTrips(time,mid)>=totalTrips){
                r=mid;
            }
            else{
                l=mid+1;
            }
        }
        
        return l;
    }
};