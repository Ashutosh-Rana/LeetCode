class Solution {
// private:
//     void recursive(int i,int& cnt,string s){
//         if(i==s.size()){
//             cnt++;
//             return;
//         }
//         if(s[i]=='0'){
//             return;
//         }
//         recursive(i+1,cnt,s);
//         if(i<s.size()-1 && s[i]!='0'){
//             string temp=s.substr(i,2);
//             stringstream ss(temp);
//             int x=0;
//             ss>>x;
//             if(x>0 && x<27){
//                 recursive(i+2,cnt,s);
//             }
//         }
//     }
public:
    int numDecodings(string s) {
        // if(s[0]=='0'){
        //     return 0;
        // }
        int n=s.size();
        vector<int> dp(n+1);
        dp[n]=1;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='0'){
                dp[i]=0;
            }
            else{
                dp[i]=dp[i+1];
            }
            if(i<n-1 && (s[i]=='1' || (s[i]=='2' && s[i+1]>='0'&& s[i+1]<='6'))){
                dp[i]+=dp[i+2];
            }
        }
        return dp[0];
    }
};