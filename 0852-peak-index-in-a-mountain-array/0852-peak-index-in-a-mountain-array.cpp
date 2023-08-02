class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size(),l=1,r=n-2,mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]){
                return mid;
            }
            else if(arr[mid]<arr[mid-1] && arr[mid]>arr[mid+1]){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return mid;
    }
};