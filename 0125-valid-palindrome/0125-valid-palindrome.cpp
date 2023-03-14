class Solution {
public:
    bool isPalindrome(string s) {
        string res="";
        for(char c:s){
            if(isalpha(c) || isdigit(c)){
                if(isalpha(c)){
                    res+=tolower(c);
                }
                else{
                    res+=c;
                }
            }
        }
        int l=0,r=res.size()-1;
        while(l<r){
            if(res[l]==res[r]){
                l++;
                r--;
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
};