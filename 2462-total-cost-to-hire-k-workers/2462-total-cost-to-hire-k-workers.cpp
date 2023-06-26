class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long res=0,n=costs.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        unordered_map<int,int> mp;
        for(int i=0;i<candidates;i++){
            if(!mp[i]){
                pq.push({costs[i],i});
                mp[i]=1;
            }
            if(!mp[n-i-1]){
                pq.push({costs[n-i-1],n-i-1});
                mp[n-i-1]=1;
            }
        }
        // cout<<n<<endl;
        int left=candidates-1,right=n-candidates;
        for(int i=0;i<k;i++){
            int minm=pq.top().first,idx=pq.top().second;
            pq.pop();
            res+=minm;
            // cout<<idx<<" "<<minm<<endl;
            if(left+1<n && idx<=left && !mp[left+1]){
                left++;
                pq.push({costs[left],left});
                mp[left]=1;
            }
            else if(right-1>=0 && idx>=right && !mp[right-1]){
                right--;
                pq.push({costs[right],right});
                mp[right]=1;
            }
        }
        return res;
    }
};