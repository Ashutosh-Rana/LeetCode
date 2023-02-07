class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n=fruits.size();
        unordered_map<int,int> mp;
        int total=0,res=0,l=0,r;
        for(r=0;r<n;r++){
            mp[fruits[r]]++;
            total++;
            while(mp.size()>2){
                mp[fruits[l]]--;
                total--;
                if(!mp[fruits[l]]){
                    mp.erase(fruits[l]);
                }
                l++;
            }
            res=max(total,res);
        }
        return res;
    }
};