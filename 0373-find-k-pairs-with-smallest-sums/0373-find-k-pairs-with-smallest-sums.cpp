class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1=nums1.size(),n2=nums2.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int sum,j=0;
        for(int i=0;i<n1 && i<k;i++){
            sum=nums1[i]+nums2[j];
            pq.push({sum,{i,j}});
        }
        vector<vector<int>> res;
        while(k && !pq.empty()){
            // cout<<k<<endl;
            int i=pq.top().second.first,j=pq.top().second.second;
            pq.pop();
            res.push_back({nums1[i],nums2[j]});
            if(j+1<n2){
                j++;
                sum=nums1[i]+nums2[j];
                pq.push({sum,{i,j}});
            }
            k--;
        }
        return res;
    }
};