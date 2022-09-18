// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        unsigned l=1,r=n;
        if(isBadVersion(1)==true){
            return 1;
        }
        while(l<=r){
            unsigned mid=(l+r)/2;
            if(mid>1 && isBadVersion(mid)==true && isBadVersion(mid-1)==false){
                return mid;
            }
            if(isBadVersion(mid)==true){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return 0;
    }
};