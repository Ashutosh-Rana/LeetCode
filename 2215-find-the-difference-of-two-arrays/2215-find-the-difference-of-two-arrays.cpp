class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size();
        vector<vector<int>> res(2);
        set<int> st;
        vector<int> v1,v2;
        // vector<int> res[2];
        for(int i=0;i<n;i++){
            if(find(nums2.begin(),nums2.end(),nums1[i])!=nums2.end() ){
                st.insert(nums1[i]);
            }
        }
        
        for(int i=0;i<n;i++){
            if(st.find(nums1[i])==st.end() && find(v1.begin(),v1.end(),nums1[i])==v1.end() ){
                v1.push_back(nums1[i]);
            }
        }
        for(int i=0;i<m;i++){
            if(st.find(nums2[i])==st.end() && find(v2.begin(),v2.end(),nums2[i])==v2.end()){
                v2.push_back(nums2[i]);
            }
        }
        res[0].resize(v1.size());
        res[1].resize(v2.size());
        // cout<<v1.size()<<" "<<v2.size()<<" "<<st.size();
        res[0]=v1;
        res[1]=v2;
        // for(int i=0;i<n;i++){
        //     if(find(nums2.begin(),nums2.end(),nums1[i])==nums2.end() &&
        //       find(res[0].begin(),res[0].end(),nums1[i])==res[0].end()){
        //         res[0].push_back(nums1[i]);
        //     }
        // }
        // for(int i=0;i<m;i++){
        //     if(find(nums1.begin(),nums1.end(),nums2[i])==nums1.end() &&
        //       find(res[1].begin(),res[1].end(),nums2[i])==res[1].end()){
        //         res[2].push_back(nums2[i]);
        //     }
        // }
        return res;
    }
}; 