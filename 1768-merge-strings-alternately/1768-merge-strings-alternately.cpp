class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        int minm=min(n,m);
        string res;
        // if()
        for(int i=0;i<minm;i++){
            res+=word1[i];
            res+=word2[i];
        }
        if(m>n){
            for(int i=n;i<m;i++){
                res+=word2[i];
            }
        }
        else if(n>m){
            for(int i=m;i<n;i++){
                res+=word1[i];
            }
        }
        return res;
    }
};