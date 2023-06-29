class Solution {
    string res="";
    // int cnt=1;
    void checkPal(string s,int i,int j){
        int l=i,r=j,n=s.size();
        while(l>=0 && r<n){
            if(s[l]==s[r]){
                l--,r++;
                continue;
            }
            else{
                break;
            }
        }
        int cnt=r-l-1;
        if(cnt>res.size()){
            // cout<<cnt<<" "<<res.size()<<endl;
            res=s.substr(l+1,cnt);
        }
    }
public:
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==1){
            return s;
        }
        for(int i=0;i<n-1;i++){
            checkPal(s,i,i);
            checkPal(s,i,i+1);
        }
        return res;
    }
};