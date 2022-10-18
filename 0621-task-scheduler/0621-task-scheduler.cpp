class Solution {
public:
    int leastInterval(vector<char>& v, int n) {
        int ans,max_len=0;
        unordered_map<char,int> mp;
        for(auto c:v){
            mp[c]++;
            max_len=max(max_len,mp[c]);
        }
        ans=(max_len-1)*(n+1);
        for(auto it:mp){
            if(it.second==max_len){
                ans++;
            }
        }
        int s=v.size();
        //cout<<s<<" "<<ans;
        return max(ans,s);
    }
};