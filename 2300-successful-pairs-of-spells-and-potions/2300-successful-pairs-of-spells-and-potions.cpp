#define ll long long
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> res;
        sort(potions.begin(),potions.end());
        int n=spells.size(),m=potions.size();
        for(int i=0;i<n;i++){
            ll cur=spells[i],l=0,r=m-1;
            while(l<=r){
                ll mid=l+(r-l)/2;
                if(cur*potions[mid]>=success){
                    r=mid-1;
                }
                else{
                l=mid+1;
                }
            }
            res.push_back(m-l);
        }
        return res;
    }
};