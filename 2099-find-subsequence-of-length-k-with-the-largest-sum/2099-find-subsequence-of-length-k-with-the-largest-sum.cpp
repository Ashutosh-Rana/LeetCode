class Solution {
private:
    int findMin(vector<int> v){
        int min_ele=v[0];
        for(int a:v){
            min_ele=min(min_ele,a);
        }
        return min_ele;
    }
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        // priority_queue<int> pq;
               
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            res.push_back(nums[i]);
            if(res.size()>k){
                int minEle=findMin(res);
                if(minEle<nums[i]){
                    auto it=find(res.begin(),res.end(),minEle);
                    res.erase(it);
                }
                else{
                    res.pop_back();
                }
            }
        }
        return res;
    }
};