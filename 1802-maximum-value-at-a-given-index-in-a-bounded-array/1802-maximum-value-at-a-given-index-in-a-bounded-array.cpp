class Solution {
private:
    long test(int n,int index,int a){
        int b=max(0,a-index);
        long res=((long)(a+b)*(a-b+1))/2;
        b=max(0,a-(n-1-index));
        res+=((long)(a+b)*(a-b+1))/2;
        return res-a;
    }
public:
    int maxValue(int n, int index, int maxSum) {
        maxSum-=n;
        int l=0,r=maxSum,mid;
        while(l<r){
            mid=(l+r+1)/2;
            if(test(n,index,mid)<=maxSum){
                l=mid;
            }
            else{
                r=mid-1;
            }
        }
        return l+1;
    }
};