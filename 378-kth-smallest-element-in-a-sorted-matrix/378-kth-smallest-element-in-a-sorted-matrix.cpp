class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        // priority_queue<int> pq;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         pq.push(matrix[i][j]);
        //         if(pq.size()>k){
        //             pq.pop();
        //         }
        //     }
        // }
        // return pq.top();
        
        int low=matrix[0][0],high=matrix[n-1][n-1];
        while(low<high){
            int mid=low+(high-low)/2,cnt=0;
            for(int i=0;i<n;i++){
                cnt+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();  //log(n) time complexity of upper bound
            }
            if(cnt<k){
                low=mid+1;
            }
            else{
                high=mid;
            }
        }
        return low;
    }
};