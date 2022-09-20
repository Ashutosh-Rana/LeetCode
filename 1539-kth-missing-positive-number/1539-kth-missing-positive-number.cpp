class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n=arr.size(),cnt=0,ele=1,i=0;
        while(cnt<k && i<n){
            if(ele!=arr[i]){
                ele++;
                cnt++;
            }
            else{
                i++;
                ele++;
            }
        }
        if(cnt==k){
            return ele-1;
        }
        return ele+k-cnt-1;
    }
};