class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.size(),cnt=0;
        for(int i=0;i<k;i++){
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u'){
                cnt++;
            }
        }
        int res=cnt;
        for(int i=k;i<n;i++){
            if(s[i]=='a' or s[i]=='e' or s[i]=='i' or s[i]=='o' or s[i]=='u'){
                cnt++;
            }
            if(s[i-k]=='a' or s[i-k]=='e' or s[i-k]=='i' or s[i-k]=='o' or s[i-k]=='u'){
                cnt--;
            }
            res=max(res,cnt);
        }
        return res;
    }
};