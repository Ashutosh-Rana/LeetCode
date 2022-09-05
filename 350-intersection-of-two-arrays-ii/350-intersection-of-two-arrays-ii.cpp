class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n1;i++){
            mp[nums1[i]]++;
        }
        vector<int> res;
        for(int i=0;i<n2;i++){
            if(mp[nums2[i]]){
                res.push_back(nums2[i]);
                mp[nums2[i]]--;
            }
        }
        return res;
    }
};