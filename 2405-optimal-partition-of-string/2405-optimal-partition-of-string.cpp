class Solution {
public:
    int partitionString(string s) {
        int n=s.size(),l=0,r=0;
        int cnt=1;
        unordered_map<char,int> mp;
//         while(r<n){
            
//             if(mp[s[r]]==0){
//                 mp[s[r]]=1;
                
//             }
//             else{
//                 l=r;
//                 cnt++;
//                 unordered_map<char,int> temp;
//                 mp=temp;
//                 mp[s[r]]=1;
//             }
//             // cout<<r<<" "<<mp[r]<<endl;
//             r++;
//         }
        for(int i=0;i<n;i++){
            if(mp[s[i]]==0){
                mp[s[i]]=1;
            }
            else{
                cnt++;
                unordered_map<char,int> temp;
                mp=temp;
                mp[s[i]]=1;
            }
        }
        return cnt;
    }
};