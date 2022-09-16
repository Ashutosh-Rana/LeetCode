class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int i1=0,i2=0,n1=nums1.size(),n2=nums2.size();
        vector<int> res;
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(nums1[i]==nums2[j] &&                                find(res.begin(),res.end(),nums1[i])==res.end()){
                    res.push_back(nums1[i]);
                    break;
                }
            }
        }
        while(i1<n1 && i2<n2){
            auto it=find(res.begin(),res.end(),nums1[i1]);
            if(nums1[i1]==nums2[i2] && it==res.end() ){
                res.push_back(nums1[i1]);
                i1++;
                i2++;
            }
            else if(n1>n2){
                i1++;
            }
            else{
                i2++;
            }
        }
        return res;
    }
};