class Solution {
public:
    int partitionString(string s) {
        int n=s.size(),l=0,r=0;
        int cnt=1;
        unordered_map<char,int> mp;
        while(r<n){
            
            if(mp[s[r]]==0){
                mp[s[r]]=1;
                
            }
            else{
                l=r;
                cnt++;
                unordered_map<char,int> temp;
                mp=temp;
                mp[s[r]]=1;
            }
            // cout<<r<<" "<<mp[r]<<endl;
            r++;
        }
        return cnt;
    }
};