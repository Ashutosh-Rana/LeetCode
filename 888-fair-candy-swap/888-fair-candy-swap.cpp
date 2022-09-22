class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int aSize=aliceSizes.size(),bSize=bobSizes.size(),sumA=0,sumB=0;
        // for(int i=0;i<aSize;i++){
        //     sumA+=aliceSizes[i];
        // }
        // for(int i=0;i<bSize;i++){
        //     sumB+=bobSizes[i];
        // }
        sumA=accumulate(aliceSizes.begin(),aliceSizes.end(),0);
        sumB=accumulate(bobSizes.begin(),bobSizes.end(),0);
        int dif=(sumA-sumB)/2;
        vector<int> res;
        unordered_set<int> s(aliceSizes.begin(),aliceSizes.end());
        for(int i=0;i<bSize;i++){
            if(s.count(dif+bobSizes[i])>0){
                return {dif+bobSizes[i],bobSizes[i]};
            }
        }
        return res;
    }
};