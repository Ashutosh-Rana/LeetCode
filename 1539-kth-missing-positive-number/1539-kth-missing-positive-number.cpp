class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size(),cnt=0,ele=1,i=0;
        // while(cnt<k && i<n){
        //     if(ele!=arr[i]){
        //         ele++;
        //         cnt++;
        //     }
        //     else{
        //         i++;
        //         ele++;
        //     }
        // }
        // if(cnt==k){
        //     return ele-1;
        // }
        // return ele+k-cnt-1;
        int l=0,h=n-1,mid;
        while(l<=h){
            mid=l+(h-l)/2;
            cnt=arr[mid]-mid-1;
            if(cnt<k){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        if(cnt==k){
            return arr[mid]-1;
        }
        if(cnt<k){
            return arr[mid]+k-cnt;
        }
        return arr[mid]-(cnt-k)-1;
    }
};