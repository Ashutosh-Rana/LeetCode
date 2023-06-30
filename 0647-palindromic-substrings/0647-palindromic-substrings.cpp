class Solution {
    // int res=0;
    int checkPal(string s,int i,int j){
        int l=i,r=j,n=s.size(),cnt=0;
        while(l>=0 && r<n){
            if(s[l]==s[r]){
                cnt++;
                l--,r++;
            }
            else{
                return cnt;
            }
        }
        return cnt;
    }
public:
    int countSubstrings(string s) {
        int res=0,n=s.size();
        for(int i=0;i<n;i++){
            res+=checkPal(s,i,i);
            res+=checkPal(s,i,i+1);
        }
        return res;
    }
};