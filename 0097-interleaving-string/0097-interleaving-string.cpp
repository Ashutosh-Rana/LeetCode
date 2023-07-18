class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.length(),n2=s2.length(),n3=s3.length();
        if(n1+n2!=n3){
            return false;
        }
        bool dp[n1+1][n2+1];
        for(int i=0;i<n1+1;i++){
            for(int j=0;j<n2+1;j++){
                if(!i && !j){
                    dp[i][j]=true;
                }
                else if(!i){
                    dp[i][j]=dp[i][j-1] && s2[j-1]==s3[i+j-1];
                }
                else if(!j){
                    dp[i][j]=dp[i-1][j] && s1[i-1]==s3[i+j-1];
                }
                else{
                    dp[i][j]=(dp[i][j-1] && s2[j-1]==s3[i+j-1]) or 
                        (dp[i-1][j] && s1[i-1]==s3[i+j-1]);
                }
            }
        }
        return dp[n1][n2];
    }
};